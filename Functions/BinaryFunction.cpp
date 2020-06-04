//
// Created by Oemer on 04.06.2020.
//

#include "BinaryFunction.h"
#include <limits>

double BinaryFunction::f(R2 &x) const {
    return (x.d1+x.d2>0)?1:0;
}

R2 *BinaryFunction::df(R2 &x) const {
    return new R2{((x.d1+x.d2)==0)?std::numeric_limits<double>::max():0,((x.d1+x.d2)==0)?std::numeric_limits<double>::max():0};
}

