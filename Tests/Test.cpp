//
// Created by Oemer on 02.06.2020.
//


#include <chrono>
#include <c++/4.8.3/stdexcept>
#include <c++/4.8.3/cstring>
#include <c++/4.8.3/iostream>
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
    for (GenericList<TestCase>::Iterator i = *tests->iterator(); i.hasNext(); k++) {
        TestCase *tc = i.next();
        auto n2 = (char *) (malloc(sizeof(char) * (tc->name->length())));
        tc->name->copy(n2, tc->name->length());
        r[k].name = new std::string(n2);
        //TODO make time record work
        r[k].start = std::time(nullptr);
        r[k].success = true;
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

        r[k].end = std::time(nullptr);
        r[k].duration = r[k].end - r[k].start;


    }
}

void Test::addTest(std::string *name, Test::func f) {
    tests->add(new TestCase(name, f));
}

int Test::count() {
    return tests->getSize();
}

Test::result *Test::getResult() {
    return r;
}

Test::~Test() {
    delete this->params;
    delete this->tests;
    delete[] this->r;
}

//TODO make strings


void Test::neqadr(void *a, void *b) {
    if (a == b) throw UnexpectedValueException(new std::string("NOT"), new std::string(""));

}

void Test::eqadr(void *a, void *b) {
    if (a != b) throw UnexpectedValueException(new std::string(""), new std::string(""));

}

void Test::printResult() {
    std::cout<<"========== Test Results ==========\n";
    for (int i = 0; i <count() ; ++i) {
        std::cout<<"\n";
        auto s = r[i].toString();
        std::cout<<*s<<"\n";
        delete s;
    }

}


Test::TestCase::TestCase(std::string *name, Test::func
f) {
    this->f = f;
    this->name = name;
}

std::string *Test::result::toString() const {
    //copy name
    char *n2 = static_cast<char *>(malloc(sizeof(char) * name->length() + 1));
    name->copy(n2, name->length());
    auto *s = new std::string(n2);
    s->append(": ");
    if (success) {
        s->append("SUCCESS!!! \n");
    } else {
        s->append("FAILED: ").append(e->what()).append("\n");
    }
    s->append("duration: ").append(std::to_string((long) duration)).append("\n");
    return s;
}


char *Test::UnexpectedValueException::what() {
    std::string s("UnexpectedValueException: Expected ");
    s.append(*e).append("but ").append(*g).append("was given.");
    auto c = new char[s.length() + 1];
    strncpy(c, s.c_str(), s.length() + 1 * sizeof(char));
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
