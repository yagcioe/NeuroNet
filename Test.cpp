//
// Created by Oemer on 02.06.2020.
//

#include <c++/4.8.3/iostream>
#include <chrono>
#include <c++/4.8.3/stdexcept>
#include "Test.h"

Test::Test(void *params[]) {
    std::cout << "create new Test" << std::endl;
    this->params = params;
    tests = new GenericList<TestCase>();
    r = nullptr;
}

void Test::run(void *args[]) {
    delete[] r;
    r = new result[count()];
    int k = 0;
    for (GenericList<TestCase>::Iterator i = *tests->iterator(); i.hasNext(); k++) {
        TestCase *tc = i.next();;
        auto n2 = (char *) (malloc(sizeof(char) * (tc->name->length())));
        tc->name->copy(n2, tc->name->length());
        r[k].name = new std::string(n2);
        r[k].start = std::time(nullptr);
        r[k].success = true;
        try {
            if (args == nullptr) {

                tc->f(nullptr);

            } else {
                tc->f(args[k]);
            }
        }
        catch (std::runtime_error &re) {
            // speciffic handling for runtime_error
            r[k].success = false;
            r[k].e = & re;
        }
        catch (std::exception &ex) {
            // speciffic handling for all exceptions extending std::exception, except
            // std::runtime_error which is handled explicitly
            r[k].success = false;
            r[k].e = & ex;
        }

        catch (...) {
            r[k].success = false;
            r[k].e = new std::exception();

        }
        r[k].end = std::time(nullptr);
        r[k].duration = r[k].end - r[k].start;
        std::cout << r[k].toString();


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

    Test::~Test()
    {
        std::cout << "delete this test" << std::endl;
        delete this->params;
        delete this->tests;
        delete[] this->r;
    }

    //TODO make char*
void Test::neq(void *a, void *b) {

    if(a==b) throw UnexpectedValueException("NOT a","b");
}

void Test::eq(void *a, void *b) {
    if(a!=b) throw UnexpectedValueException("a","b");
}


Test::TestCase::TestCase(std::string * name, Test::func
    f) {
        this->f = f;
        this->name = name;
    }

    std::string *Test::result::toString() {
        //copy name
        char *n2 = static_cast<char *>(malloc(sizeof(char) * name->length() + 1));
        name->copy(n2, name->length());
        auto *s = new std::string(n2);
        s->append(": ");
        if (success) {
            s->append("SUCCESS!!! \n");
        } else {
            s->append("FAILED \n");
        }
        s->append("duration: ");
        s->append(std::to_string((long) duration));
        s->append("\n");
        return s;
    }

Test::UnexpectedValueException::UnexpectedValueException(char *expected, char *given) {
e=expected;
g=given;
}

char * Test::UnexpectedValueException::what() {
    std::string s("UnexpectedValueException: Expected ");
    s.append(e).append("but ").append("g").append("was given.");
    auto c =new char[s.length()+1];
    memcpy( c,s.c_str(),s.length()+1* sizeof(char));
    return c;
}

Test::UnexpectedValueException::~UnexpectedValueException() {
    delete e;
    delete g;
}
