//
// Created by Oemer on 02.06.2020.
//

#include "Test.h"

Test::Test(void *params) {
    this->params=params;
    tests = new GenericList<TestCase>();
}

Test::result * Test::run(void** args) {
    int k =0;
    for (GenericList<TestCase>::Iterator i = *tests->iterator(); i.hasNext() ; k++) {
        try {
            i.next();
        }
        catch(...) {
            std::exception_ptr p = std::current_exception();
        }
    }
    return nullptr;
}

void Test::addTest(std::string *name, Test::func) {

}



