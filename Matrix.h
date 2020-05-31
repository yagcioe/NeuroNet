//
// Created by Oemer on 31.05.2020.
//

#ifndef NEURONET_MATRIX_H

#include "Dimension.h"
#define NEURONET_MATRIX_H
template <class T>
class Matrix{
private:
    T* values;
    Dimension dim;
public:
    Matrix(T* arrOfValues);
    Dimension getDim();
    T* getValueArray();
    Matrix operator *(Matrix &m);
    T* get(int n,int m);
};
#endif //NEURONET_MATRIX_H
