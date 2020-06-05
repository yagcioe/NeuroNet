//
// Created by Oemer on 31.05.2020.
//

#ifndef NEURONET_MATRIX_H


#define NEURONET_MATRIX_H

#include "Dimension.h"
#include "IMatrixValue.h"
#include <string>
#include <cassert>

template<typename T>
class Matrix {
private:
    T *values;
    Dimension dim;

public:

/**
 *
 * @param rows number of rows
 * @param cols number of collumns
 * @param arrOfValues  1 dimensional array of length rows*cols filled with pointers
 */

    explicit Matrix(int rows, int cols, T *arrOfValues ,bool copy=true) {
        static_assert(std::is_base_of<IMatrixValue<T>, T>::value, "Template Type must implement IMatrixValue");

        dim = {rows, cols};
        if(copy){
            values = new T[rows*cols];
            for (int i = 0; i <dim.n*dim.m ; ++i) {
                values[i]= arrOfValues[i];
            }
        }else {values = arrOfValues;}

    }

/**
 *
 * @param rows
 * @param cols
 * @return Zero initialised rows x cols Matrix
 */

    explicit Matrix(int rows, int cols) {
        static_assert(std::is_base_of<IMatrixValue<T>, T>::value,
                      "Template Type must implement IMatrixValue");
        dim = {rows, cols};
        values = new T[rows*cols];
        T t;
        for (int i = 0; i <dim.n*dim.m ; ++i) {
            values[i]= t;
        }

    }

    ~Matrix(){
        delete [] values;
    }

    void set(int row, int col, T* t) {
        assert(row < dim.n);
        assert(col < dim.m);
        delete &values[row*dim.m+col];
        values[row*col] = *t;
    }
    /**
     *
     * @param i
     * @param rowValue assumes has enough length
     */
    void setRow(int i, T *rowValues) {
        assert(i < dim.n);
        for (int j = 0; j <dim.m ; ++j) {
            delete &values[i*dim.m+j];
            values[i*dim.m+j]=rowValues[j];}


    }




    void setCol(int i, T* colValues) {
        assert(i >= 0 && i < dim.m && "Index i out of Range");
        for (int j = 0; j < dim.n; ++j) {
            delete values[j*dim.m+i];
            values[j*dim.m+i] = colValues[j];
        }
    }

    T* get(int n, int m) {
        assert(n < dim.n);
        assert(m<dim.m);
        return &values[n*dim.m+m];
    }



    T*  getCol(int i) {
        assert(i < dim.m);
        auto col = new T* [dim.n];
        for (int j = 0; j < dim.n; ++j) {
            col[j] = values[j*dim.m+i];
        }
        return col;
    }




    Dimension getDim() const{
        return dim;
    }

    int rows() const{
        return dim.n;
    }

    int cols() const {
        return dim.m;
    }


};


#endif //NEURONET_MATRIX_H
