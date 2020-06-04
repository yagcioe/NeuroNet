//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_LIMITEDLINEARFUNCTION_H
#define NEURONET_LIMITEDLINEARFUNCTION_H

#include "IFunction.h"

class LimitedLinearFunction : IFunction<R2, double, R2> {
    double a;
    double m;
public:
    double getA() const;

    void setA(double a);

    double getM() const;

    void setM(double m);

    LimitedLinearFunction(double a, double m);

    double f(R2 &x)const override;

    R2* df(R2 &x) const override;


};


#endif //NEURONET_LIMITEDLINEARFUNCTION_H
