//
// Created by Oemer on 03.06.2020.
//



#include "Test.h"
#include "../Math/LinAlg/Matrix.h"

void MatrixCloneTest(void*){
    Matrix m(3,4);
    m.setRow(0,  new double[4]  {1,2,3,4});
    m.setRow(1,new double[4]{5,6,7,8});
    m.setRow(2,new double[4]{9,10,11,12});
    Matrix *m2=m.clone();
    for (int i = 0; i < 3 ; ++i) {
        //unterschiedliche speicheradressen
        Test::neqadr(m.getRow(i),m2->getRow(i));
        for (int j = 0; j < 4; ++j) {
            //gleiche werte
            Test::eq(m.getRow(i)[j],m2->getRow(i)[j]);
        }
    }
    delete m2;
}

void test(){
    Test t(nullptr);
    std::string s("MatrixClone");
    t.addTest(s, MatrixCloneTest);
    t.run(nullptr);
    t.printResult();
}

