//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_BINARYFUNCTION_H
#define NEURONET_BINARYFUNCTION_H


#include "IFunction.h"

class BinaryFunction: IFunction<R2,double,R2>{
    double f(R2 &x) const;
    R2* df(R2 &x) const;

};


#endif //NEURONET_BINARYFUNCTION_H
