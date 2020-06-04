//
// Created by Oemer on 04.06.2020.
//

#ifndef NEURONET_IFUNCTION_H
#define NEURONET_IFUNCTION_H

#include <cmath>
#include <c++/4.8.3/cstdlib>

struct R2 {
    double d1;
    double d2;

    R2 operator+(R2 &o) {
       R2 r{d1+o.d1,d2+o.d2};
       return r;
    }
};

struct R3 {
    double d1;
    double d2;
    double d3;
    R3 operator+(R3 &o) {
        R3 r{d1+o.d1,d2+o.d2,d3+o.d3};
        return r;
    }
};

template<int n>
struct R {
    double *d;

    R() {
        d = new double[n];
    }

    ~R(){
        delete[] d;
    }
    R operator+(R &o) {
        R<n> r;
        for(int i =0;i<n;++i){
            r.d[i]=d[i]+o.d[i];
        }
        return r;
    }
};

template<class Defintionsbereich, class Bild, typename Gradient>
class IFunction {
public:
    virtual Bild f(Defintionsbereich &x) const ;
    virtual Gradient * df(R2 &x) const ;

};


#endif //NEURONET_IFUNCTION_H
