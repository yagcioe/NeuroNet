//
// Created by Oemer on 05.06.2020.
//

#ifndef NEURONET_MATRIXVALUETEST_H
#define NEURONET_MATRIXVALUETEST_H


#include "IMatrixValue.h"

class MatrixValueTest: public IMatrixValue<MatrixValueTest> {
public:
    double d;
    explicit MatrixValueTest(double value);
    MatrixValueTest();
    std::string *toString() override ;
    MatrixValueTest operator*(MatrixValueTest &o) override;
    void operator=(MatrixValueTest &o)override;
    bool operator==(MatrixValueTest &o)override;
    MatrixValueTest clone()override;
};


#endif //NEURONET_MATRIXVALUETEST_H
