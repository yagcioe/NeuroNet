//
// Created by Oemer on 02.06.2020.
//

#ifndef NEURONET_TEST_H
#define NEURONET_TEST_H


#include <c++/4.8.3/string>
#include "GenericList.h"

class Test {

public:

    typedef void (*func )(void* args);

    class result{
    public:
        std::string *name;
        long start;
        long end;
        long duration;
        bool success;
        std::exception_ptr e;

        std::string toString();
    };
protected:
    class TestCase{
    public:
        std::string *name;
        func f;
        TestCase(std::string *name,func f);
    };
public:
    int count();
    explicit Test( void *params[]);
    ~Test();

    /**
     *
     * @param args array of length of number of tests
     * @return array of results length of number of tests
     */
    void run(void* args[]);
    result* getResult();
    void addTest(std::string* name,func);

private:
    void **params;
    GenericList<TestCase>* tests;
    result* r;



};


#endif //NEURONET_TEST_H
