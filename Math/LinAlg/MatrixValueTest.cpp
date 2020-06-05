//
// Created by Oemer on 05.06.2020.
//

#include "MatrixValueTest.h"

std::string *MatrixValueTest::toString() {
    return new std::string (std::to_string(d));
}

MatrixValueTest MatrixValueTest::operator*(MatrixValueTest &o) {
    return  MatrixValueTest(d * o.d);
}

MatrixValueTest::MatrixValueTest(double value):d(value) {}

void MatrixValueTest::operator=(MatrixValueTest &o) {
    d = o.d;
}

MatrixValueTest MatrixValueTest::clone() {
    return MatrixValueTest(d);
}

bool MatrixValueTest::operator==(MatrixValueTest &o) {
    return d==o.d;
}

MatrixValueTest::MatrixValueTest() {
    d=0;
}
