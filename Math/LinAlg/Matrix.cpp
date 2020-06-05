//
// Created by Oemer on 31.05.2020.
//


#include <cassert>
#include "Matrix.h"
#include <stdio.h>


/**
 *
 * @param rows number of rows
 * @param cols number of collumns
 * @param arrOfValues  1 dimensional array of length rows*cols filled with pointers
 */
Matrix::Matrix(int rows, int cols, void **arrOfValues) {
    dim = {rows, cols};
    values = arrOfValues;

}

/**
 *
 * @param rows
 * @param cols
 * @return Zero initialised rows x cols Matrix
 */

Matrix::Matrix(int rows, int cols) {
    dim = {rows, cols};
    values = new void *[rows*cols];
    for (int i = 0; i < rows; ++i) {
        values[i] = new double[cols];
    }

}





int Matrix::rows() {
    return dim.n;
}


int Matrix::cols() {
    return dim.m;
}

void* Matrix::get(int n, int m) {
    return values[n*m];
}

void* *Matrix::getRow(int i) {
    assert(i < dim.n);

    return &values[i*dim.m];
}

void* *Matrix::getCol(int i) {
    assert(i < dim.m);
    auto col = new void*[dim.n];
    for (int j = 0; j < dim.n; ++j) {
        col[j] = values[j*i];
    }
    return col;
}

void Matrix::set(int row, int col, void* d) {
    assert(row < dim.n);
    assert(col < dim.m);

    values[row*col] = d;
}
/**
 * copies pointers of this array
 * @param i
 * @param rowValue
 */
void Matrix::setRow(int i, void* *rowValue) {
    assert(sizeof(rowValue) == sizeof(values[i]));
    assert(i < dim.n);
    for (int j = 0; j <dim.m ; ++j) {
        values[i*dim.m+j]=rowValue[j];
    }


}

void Matrix::setCol(int i, int length, void* *colValue) {
    assert((length == dim.n) && "Collumn has unexpected size");
    assert(i >= 0 && i < dim.m && "Index i out of Range");
    for (int j = 0; j < dim.n; ++j) {
        values[j*i] = colValue[j];
    }
}


Dimension Matrix::getDim() {
    return dim;
}


/*double **Matrix::getValueArray() {
    return values;
}
*/

Matrix::~Matrix() {
    delete[] values;
}




