//
// Created by Oemer on 04.06.2020.
//

#include "LinearFunction.h"

double LinearFunction::getA() const {
    return a;
}

void LinearFunction::setA(double a) {
    LinearFunction::a = a;
}

double LinearFunction::getM() const {
    return m;
}

void LinearFunction::setM(double m) {
    LinearFunction::m = m;
}

LinearFunction::LinearFunction(double a, double m) : a(a), m(m) {}

double LinearFunction::f(R2 &x) const {
    return m * (x.d1 + x.d2) + a;
}

R2 *LinearFunction::df(R2 &x) const {
    return new R2{m, m};
}
