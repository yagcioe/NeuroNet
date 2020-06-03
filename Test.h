//
// Created by Oemer on 02.06.2020.
//

#ifndef NEURONET_TEST_H
#define NEURONET_TEST_H


#include <c++/4.8.3/string>
#include "LinkedList.h"

class Test {

protected:

    void* params;
    LinkedList tests;
    explicit Test( void* params);

    virtual void init();

    virtual const LinkedList*  run();

    void addTest(std::string Name,bool (*f)(void * args));


};


#endif //NEURONET_TEST_H
