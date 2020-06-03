//
// Created by Oemer on 03.06.2020.
//


#include <c++/4.8.3/iostream>
#include "Test.h"
#include "../Matrix.h"

void MatrixCloneTest(void*){
    Matrix m(3,4);
    m.setRow(0,  new double[4]  {1,2,3,4});
    m.setRow(1,new double[4]{5,6,7,8});
    m.setRow(2,new double[4]{9,10,11,12});
    Matrix m2=m.clone();
    for (int i = 0; i < 3 ; ++i) {
        //unterschiedliche speicheradressen
        Test::neqadr(m.getRow(i),m2.getRow(i));
        for (int j = 0; j < 4; ++j) {
            //gleiche werte
            Test::eq(m.getRow(i)[j],m2.getRow(i)[j]);
        }
    }
}

void test(){
        Test t(nullptr);
        t.addTest( (new std::string("MatrixClone")), MatrixCloneTest);
    t.run(nullptr);
    std::cout<<"Result:"<<*t.getResult()->toString()<<std::endl;


}

