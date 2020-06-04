//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_LINEARFUNCTION_H
#define NEURONET_LINEARFUNCTION_H


#include "IFunction.h"

class LinearFunction : IFunction<R2, double, R2> {
    double a;
    double m;
public:
    double getA() const;

    void setA(double a);

    double getM() const;

    void setM(double m);

    LinearFunction(double a, double m);

    double f(R2 &x)const override;

    R2* df(R2 &x) const override;


};


#endif //NEURONET_LINEARFUNCTION_H
