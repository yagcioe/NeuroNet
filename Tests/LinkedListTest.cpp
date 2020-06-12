//
// Created by Oemer on 05.06.2020.
//

#include "LinkedListTest.h"
#include "Test.h"






void testAdd(void* arg) {
    auto l = new GenericList<int>();
    int* i,*j,*k,*el,*m;
    int *n = new int;
    Test::eqadr((void *) 0,(void *) l->getSize());
    i =new int(12);
    l->add(i);
    //l:[12]
    Test::eqadr((void *) 12,(void *) *l->get(0));
    Test::eqadr((void *) 1,(void *) l->getSize());
    j =new int(13);
    l->add(j);
    //l:[12,13]
    Test::eqadr((void *) 12,(void *) *l->get(0));
    Test::eqadr((void *) 13,(void *) *l->get(1));
    Test::eqadr((void *) 2,(void *) l->getSize());
    k =new int(14);
    l->addFirst(k);
    //l:[14,12,13]
    Test::eqadr((void *) 14,(void *) *l->get(0));
    Test::eqadr((void *) 12,(void *) *l->get(1));
    Test::eqadr((void *) 3,(void *) l->getSize());

    el =new int(42);
    //l:[14,12,13]
    l->addAt(1,el);
    //l:[14,42,12,13]
    Test::eqadr((void *) 14,(void *) *l->get(0));
    Test::eqadr((void *) 42,(void *) *l->get(1));
    Test::eqadr((void *) 4,(void *) l->getSize());

    m= new int(1337);
    //l:[14,42,12,13]
    l->addAt(l->getSize(),m);
    //l:[14,42,12,13,1337]
    Test::eqadr((void *) 1337,(void *) *l->get(4));
    Test::eqadr((void *) *l->get(l->getSize()-1),(void *) *l->get(4));

    *n= 6942069;
    l->addLastCopy(n);
    //l:[14,42,12,13,1337,6942069]
    delete n;
    Test::eqadr((void *) 6942069,(void *) *l->get(l->getSize()-1));




    delete l;
}

void testRun() {
    Test t(nullptr);
    //TODO add all functions
    t.addTest("testAdd",testAdd);

    t.run(nullptr);
    t.printResult();
}