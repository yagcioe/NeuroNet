//
// Created by Oemer on 02.06.2020.
//

#include <c++/4.8.3/iostream>
#include <chrono>
#include "Test.h"

Test::Test(void *params[]) {
    std::cout<<"create new Test"<<std::endl;
    this->params = params;
    tests = new GenericList<TestCase>();
}

void Test::run(void *args[]) {
    delete r;
    r=(result *) malloc(sizeof(result) * tests->getSize());
    int k = 0;
    for (GenericList<TestCase>::Iterator i = *tests->iterator(); i.hasNext(); k++) {
        TestCase *tc = i.next();
        result thisRes= r[k];
        thisRes.name = tc->name;
        thisRes.start= std::time(0);
        thisRes.success= false;
        try {
            if (args == nullptr) {
                tc->f(nullptr);
            }
            else {
            tc->f(args[k]);
        }
        }catch (...) {
            thisRes.success= false;
            thisRes.e=std::current_exception();
        }
        thisRes.end=std::time(0);
        thisRes.duration=thisRes.end-thisRes.start;
        std::cout<<thisRes.toString();

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
    std::cout<<"delete this test"<<std::endl;
delete this->params;
delete this->tests;
delete this->r;
}


Test::TestCase::TestCase(std::string *name, Test::func f) {
    this->f = f;
    this->name = name;
}

std::string Test::result::toString() {
     std::string s(*name);
     s.append(": ");
     if(success==true){
         s.append("SUCCESS \n");
     }else{
         s.append("FAILED \n");
     }
     s.append("duration: ");
     s.append(std::to_string((long) duration));
     s.append("\n");
}
