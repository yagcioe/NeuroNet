//
// Created by Oemer on 02.06.2020.
//


#include <chrono>
#include <iostream>
#include <cstring>


#include "Test.h"

Test::Test(void *params[]) {
    this->params = params;
    tests = new GenericList<TestCase>();
    r = nullptr;
}

void Test::run(void *args[]) {
    delete[] r;
    r = new result[count()];
    int k = 0;
    GenericList<TestCase>::Iterator *i = tests->iterator();
    for (; i->hasNext(); k++) {
        TestCase *tc = i->next();

        //copy string
        //or this might get leaked

        r[k].name = new std::string(*tc->name);

        //TODO make time record more precise
        r[k].start = clock();
        r[k].success = true;
        r[k].e = nullptr;
        try {
            if (args == nullptr) {

                tc->f(nullptr);

            } else {
                tc->f(args[k]);
            }
        }
        catch (UnexpectedValueException &ue) {
            // speciffic handling for runtime_error
            r[k].success = false;
            r[k].e = &ue;
        }


        r[k].end = clock();
        r[k].duration = ((r[k].end - r[k].start) * 1000) / ((double) CLOCKS_PER_SEC);
    }
    delete i;
}

void Test::addTest(std::string &name, Test::func f) {
    tests->add(new TestCase(name, f));
}

int Test::count() {
    return tests->getSize();
}

Test::result *Test::getResult() {
    return r;
}

Test::~Test() {
    delete params;
    while (!tests->isEmpty()) {
        tests->deleteAt(0);
    }
    delete tests;
    delete[] r;
}


void Test::neqadr(void *a, void *b) {

    if (a == b) {
        auto *expected = new std::string("NOT");
        expected->append(std::to_string((unsigned long) a));
        std::cout<<"e:"<<*expected;
        auto *given = new std::string(std::to_string((unsigned long) b));
        throw UnexpectedValueException(expected, given);
    }

}

void Test::eqadr(void *a, void *b) {
    if (a != b){
        auto *expected = new std::string(std::to_string((long) a));
        auto *given = new std::string(std::to_string((long) b));
        throw UnexpectedValueException(expected, given);
        }

}

void Test::printResult() {
    std::cout << "========== Test Results ==========\n";
    for (int i = 0; i < count(); ++i) {
        std::cout << "\n";
        auto s = r[i].toString();
        std::cout << *s << "\n";
        delete s;
    }

}

/**
 *
 * @param name string whitch is going to be copied
 * @param f
 */
Test::TestCase::TestCase(std::string &name, Test::func
f) {
    this->f = f;
    this->name = new std::string(name);
}

Test::TestCase::~TestCase() {
    delete name;

}

std::string *Test::result::toString() const {
    auto n2 = new char[name->length() + 1];
    std::strncpy(n2, name->c_str(), name->length() + 1);
    auto *s = new std::string(n2);
    delete[] n2;
    s->append(": ");
    if (success) {
        s->append("SUCCESS!!! \n");
    } else {
        s->append("FAILED: ").append(e->what()).append("\n");
    }
    s->append("duration: ").append(std::to_string((long) duration)).append("ms\n");
    return s;
}

Test::result::~result() {
    delete name;
    delete e;

}


char *Test::UnexpectedValueException::what() {
    std::string s("UnexpectedValueException: Expected ");
    s.append(*e).append(" but ").append(*g).append(" was given.");
    auto c = new char[s.length() + 1];
    strncpy(c, s.c_str(), s.length() * sizeof(char));
    c[s.length() + 1 * sizeof(char)] = '\0';
    return c;
}

Test::UnexpectedValueException::~UnexpectedValueException() {
    delete e;
    delete g;
}

Test::UnexpectedValueException::UnexpectedValueException(std::string *expected, std::string *given) {
    e = expected;
    g = given;
}
