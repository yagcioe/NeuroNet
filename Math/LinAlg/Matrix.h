//
// Created by Oemer on 31.05.2020.
//

#ifndef NEURONET_MATRIX_H


#define NEURONET_MATRIX_H

#include "Dimension.h"
#include <string>

class Matrix {
private:
    void **values;
    Dimension dim;

    static void **clone2dArray(int rows, int cols, void **arr);

public:
    explicit Matrix(int rows, int cols, void **arrOfValues);

    explicit Matrix(int rows, int cols);

    ~Matrix();

    Dimension getDim();

    Matrix *clone();

    void* get(int row, int col);

    void* *getRow(int i);

    void* *getCol(int i);

    void set(int row, int col, void* d);

    void setRow(int i, void* *rowValue);

    void setCol(int i, int length, void* *colValue);

    int rows();

    int cols();



};


#endif //NEURONET_MATRIX_H
