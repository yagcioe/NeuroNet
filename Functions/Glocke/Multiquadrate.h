//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_MULTIQUADRATE_H
#define NEURONET_MULTIQUADRATE_H


#include "../IFunction.h"

class Multiquadrate: public IFunction<R2,double,R3> {

    double a;
    double a2;
public:
    explicit Multiquadrate(double alpha);
    double f(R2& x) override;
    R3* df(R2& x) override;
    void setAlpha(double alpha);
    double getAlpha() const;


};


#endif //NEURONET_MULTIQUADRATE_H
