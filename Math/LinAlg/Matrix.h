//
// Created by Oemer on 31.05.2020.
//

#ifndef NEURONET_MATRIX_H


#define NEURONET_MATRIX_H

#include "Dimension.h"
#include <string>

class Matrix{
private:
    double** values;
    Dimension dim;
    static double **clone2dArray(int rows,int cols,double **arr);
public:
    explicit Matrix(int rows,int cols,double** arrOfValues);
    explicit Matrix(int rows,int cols);
    ~Matrix();
    Dimension getDim();

    //double** getValueArray();
    Matrix operator *(Matrix &m);
    static Matrix matmul(Matrix &m1,Matrix &m2);
    static Matrix * scale(double d, Matrix m);
    Matrix * clone();
    double get(int row,int col);
    double* getRow(int i);
    double* getCol(int i);
    void set(int row,int col, double d);
    void setRow(int i,double* rowValue);
    void setCol(int i,int length,const double* colValue);
    int rows ();
    int cols();


    std::string toString();
    static std::string toString(Matrix &m);
};



#endif //NEURONET_MATRIX_H
