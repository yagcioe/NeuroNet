//
// Created by Oemer on 04.06.2020.
//

#include "Gauss.h"

Gauss::Gauss(double sigma):sigma(sigma),sigma2(sigma*sigma),sigma3(sigma2*sigma){}

double Gauss::f(R2 &x) const {
    return exp(-(((x.d1-x.d2)*(x.d1-x.d2))/(2*sigma2)));
}

R3* Gauss::df(R2& x) const{
    auto r = new R3;
    double u=(x.d2-x.d1)/(sigma2);
    r->d1=u*f(x);
    r->d2=(-u)*f(x);
    r->d3=(((x.d1-x.d2)*(x.d1-x.d2))/(4*sigma3));
    return r;
}

void Gauss::setSigma(double sig) {
    this->sigma2=sig*sig;
    this->sigma3=sigma2*sig;
}

double Gauss::getSigma() const {
    return sigma;
}

