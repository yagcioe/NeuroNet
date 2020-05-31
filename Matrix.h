//
// Created by Oemer on 31.05.2020.
//

#ifndef NEURONET_MATRIX_H

#include "Dimension.h"
#define NEURONET_MATRIX_H
template <typename T>
class Matrix{
private:
    T* values;
    Dimension dim;
public:
    Matrix(T* arrOfValues);
    int getDim();
    T* getValues();
    Matrix operator *(Matrix &m);
};
#endif //NEURONET_MATRIX_H
