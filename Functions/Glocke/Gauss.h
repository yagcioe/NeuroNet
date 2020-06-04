//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_GAUSS_H
#define NEURONET_GAUSS_H


#include "../IFunction.h"


class Gauss:public  IFunction<R2,double,R3> {
private:
    double sigma;
    double sigma2;
    double sigma3;
public:


    explicit Gauss(double sigma);
    double f(R2& x) override;
    R3 * df(R2& x) override;
    void setSigma(double sigma);
    double getSigma() const;



};


#endif //NEURONET_GAUSS_H
