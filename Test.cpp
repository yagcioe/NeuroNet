//
// Created by Oemer on 02.06.2020.
//

#include "Test.h"

Test::Test(void *params): {
    this->params=params;
}

const LinkedList * Test::run() {
    for (LinkedList::Iterator i = *tests.iterator(); i.hasNext() ; ) {
        (Test::func)i.next()
    }
    return nullptr;
}

void Test::init() {
    return;
}
