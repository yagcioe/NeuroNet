//
// Created by Oemer on 02.06.2020.
//

#ifndef NEURONET_TEST_H
#define NEURONET_TEST_H


#include <c++/4.8.3/string>
#include "GenericList.h"

class Test {

public:
    typedef void (*func )(void * args);
    struct result{
        long start;
        long end;
        long duration;
        bool success;
        std::exception e;
    };
protected:
    class TestCase{
    public:
        std::string name;
        func f;
        TestCase(std::string name,func f);
    };
public:

    void* params;
    GenericList<TestCase>* tests;
    explicit Test( void* params);

    void init();

    result* run(void** args);

    void addTest(std::string* name,func);



};


#endif //NEURONET_TEST_H
