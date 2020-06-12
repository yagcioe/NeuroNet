//
// Created by Oemer on 03.06.2020.
//



#include "Test.h"
#include "../Math/LinAlg/Matrix.h"
#include "../Math/LinAlg/MatrixValueTest.h"


//TODO
void testConstructor(void* p){

    //sollte mit nullpointer initialisiert sein
    Matrix<MatrixValueTest> m(3,4);
    Test::eqadr((void *) 3, (void *) m.rows());
    Test::eqadr((void *) 4, (void *) m.cols());


}

void test(){
    Test t(nullptr);
    std::string t1("Matrix");
    t.addTest(t1, testConstructor);
    t.run(nullptr);
    t.printResult();

}


