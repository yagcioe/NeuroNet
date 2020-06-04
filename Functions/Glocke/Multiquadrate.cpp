//
// Created by Oemer on 04.06.2020.
//

#include "Multiquadrate.h"

double Multiquadrate::f(R2& x) {
    return sqrt((x.d1+x.d2)*(x.d1+x.d2)+a2);
}

R3* Multiquadrate::df(R2& x) {
    double u =x.d1-x.d2;
    double v= 1/(sqrt((x.d1*-x.d2)*(x.d1*-x.d2)));
    R3 *r= new R3 {u*v,(-u)*v,a*v};
    return r;
}

Multiquadrate::Multiquadrate(double alpha):a(alpha),a2(alpha*alpha) {}

void Multiquadrate::setAlpha(double alpha) {
    a=alpha;
    a2=alpha*alpha;
}

double Multiquadrate::getAlpha() const {
    return a;
}
