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

//testmethod to fund mem leak
char* Test::en(TestCase *tc){
    return new char[tc->name->length()+1];

}
std::string* str(char* n){
    return new std::string(n);
}

void Test::allocateR(){
    delete[] r;
    r = new result[count()];
}


void Test::run(void *args[]) {
    allocateR();
    int k = 0;
    for (GenericList<TestCase>::Iterator i = *tests->iterator(); i.hasNext(); k++) {
        TestCase *tc = i.next();

        //copy string
        r[k].name = new std::string(*tc->name);

        //TODO make time record work
        r[k].start = std::time(nullptr);
        r[k].success = true;
        r[k].e= nullptr;
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
    while(!tests->isEmpty()){
        tests->deleteAt(0);
    }
    delete tests;
    /*if(r!= nullptr){
    for(int i = 0;i<count();i++){
      r[i].~result();
    }}*/
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
    auto n2= new char[name->length()+1];
    std::strncpy(n2,name->c_str(), name->length()+1);
    auto *s = new std::string(n2);
    delete[] n2;
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
