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
    explicit Matrix(T *arrOfValues);
    explicit Matrix(int rows,int cols);
    Dimension getDim();

    T *getValueArray();
    Matrix operator *(Matrix &m);
    T* get(int n,int m);
    int rows();
    int cols();

};



#endif //NEURONET_MATRIX_H
