//
// Created by Oemer on 02.06.2020.
//

#ifndef NEURONET_TEST_H
#define NEURONET_TEST_H


#include <c++/4.8.3/string>
#include "LinkedList.h"

class Test {
public:
    typedef bool (*func )(void * args);
    struct result{
        long start;
        long end;
        long duration;
        bool success;
    };
protected:

    void* params;
    LinkedList tests;
    explicit Test( void* params);

    virtual void init();

    virtual const LinkedList*  run();

    void addTest(std::string Name,func);


};


#endif //NEURONET_TEST_H
