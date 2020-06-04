//
// Created by Oemer on 04.06.2020.
//

#include "LimitedLinearFunction.h"

double LimitedLinearFunction::getA() const {
    return a;
}

void LimitedLinearFunction::setA(double a) {
    LimitedLinearFunction::a = a;
}

double LimitedLinearFunction::getM() const {
    return m;
}

void LimitedLinearFunction::setM(double m) {
    LimitedLinearFunction::m = m;
}

LimitedLinearFunction::LimitedLinearFunction(double a, double m) : a(a), m(m) {}

double LimitedLinearFunction::f(R2 &x) const {
    return fmin(fmax(m * (x.d1 + x.d2) + a, 0), 1);

}

R2 *LimitedLinearFunction::df(R2 &x) const {
    return new R2{(x.d1 < 0) ? 0 : (1 > x.d1) ? 0 : m, (x.d2 < 0) ? 0 : (1 > x.d2) ? 0 : m};
}
