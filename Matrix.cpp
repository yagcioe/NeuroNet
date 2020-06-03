//
// Created by Oemer on 31.05.2020.
//


#include <cassert>
#include "Matrix.h"
#include <stdio.h>
#include <c++/4.8.3/iostream>

/**
 *
 * @param rows number of rows
 * @param cols number of collumns
 * @param arrOfValues  2d array pointer
 */
Matrix::Matrix(int rows, int cols, double **arrOfValues) {
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
    values = (double **) malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i) {
        values[i] = (double *) calloc(cols, sizeof(double));
    }

}

double **Matrix::clone2dArray(int rows, int cols, double **arr) {
    auto **ret = (double **) (malloc(sizeof(double **) * rows));
    for (int i = 0; i < rows; ++i) {
        auto *row = (double *) (malloc(sizeof(double *) * cols));
        for (int j = 0; j < cols; ++j) {
            //elements must be primitive or = must be overridden
                        row[j] = arr[i][j];
        }

        ret[i] = row;
    }

    return ret;
}

Matrix Matrix::clone() {
    Matrix ret(dim.n, dim.m, Matrix::clone2dArray(dim.n, dim.m, this->values));
    return ret;
}


int Matrix::rows() {
    return dim.n;
}


int Matrix::cols() {
    return dim.m;
}

double Matrix::get(int n, int m) {
    return values[n][m];
}

double *Matrix::getRow(int i) {
    assert(i < dim.n);
    return values[i];
}

double *Matrix::getCol(int i) {
    assert(i < dim.m);
    auto *col = (double *) malloc(sizeof(values));
    for (int j = 0; j < dim.n; ++j) {
        col[j] = values[j][i];
    }
}

void Matrix::set(int row, int col, double d) {
    assert(row < dim.n);
    assert(col < dim.m);

    values[row][col] = d;
}

void Matrix::setRow(int i, double *rowValue) {
    assert(sizeof(rowValue) == sizeof(values[i]));
    assert(i < dim.n);
    values[i] = rowValue;

}

void Matrix::setCol(int i, int length, const double *colValue) {
    assert((length == dim.n) && "Collumn has unexpected size");
    assert(i >= 0 && i < dim.m && "Index i out of Range");
    for (int j = 0; j < dim.n; ++j) {
        values[j][i] = colValue[j];
    }
}


Dimension Matrix::getDim() {
    return dim;
}


/*double **Matrix::getValueArray() {
    return values;
}
*/

Matrix Matrix::operator*(Matrix &m) {
    return matmul(*this, m);
}


Matrix Matrix::matmul(Matrix &m1, Matrix &m2) {
    assert(m1.dim.m == m2.dim.n);
    Matrix ret(m1.dim.n, m2.dim.m);

    for (int i = 0; i < m1.dim.n; ++i) {
        for (int j = 0; j < m2.dim.m; ++j) {
            for (int k = 0; k < m1.dim.m; ++k) {
                ret.set(i, j, ret.get(i, j) + m1.get(i, k) * m2.get(k, j));
            }
        }
    }
    return ret;
}


Matrix Matrix::scale(double d, Matrix m) {
    Matrix mm = m.clone();
    for (int i = 0; i < m.dim.n; ++i) {
        for (int j = 0; j < m.dim.m; ++j) {
            mm.set(i, j, m.get(i, j) * d);
        }
    }
}




std::string Matrix::toString() {
    return toString(*this);
}

std::string Matrix::toString(Matrix &m) {
    std::string s("[");
    for (int i = 0; i < m.dim.n; ++i) {
        s.append("[");
        for (int j = 0; j < m.dim.m; ++j) {
            if (j != 0) {
                s.append(", ");
            }
            s.append(std::to_string(m.get(i, j)));
        }

        s.append("]");
        if (i != m.dim.n - 1) { s.append("\n"); }
    }
    s.append("]");
    return s;
}




