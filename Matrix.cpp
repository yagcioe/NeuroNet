//
// Created by Oemer on 31.05.2020.
//


#include <cassert>
#include "Matrix.h"
#include <stdio.h>
#include <c++/4.8.3/iostream>


Matrix::Matrix(double **arrOfValues) {
    dim = { sizeof(arrOfValues),sizeof(arrOfValues[0])};

    //checke ob Eingabearray korrekt geformt ist
    for (int i = 1; i < dim.n; ++i) {
        assert((sizeof(arrOfValues[i]) == dim.m));
    }
    values=arrOfValues;

}




double  Matrix::get(int n, int m) {
    return values[n][m];
}



Dimension Matrix::getDim() {
    return dim;
}



double** Matrix::getValueArray() {
    return values;
}


Matrix Matrix::operator*(Matrix &m) {
    return matmul(*this,m);
}



int Matrix::rows() {
    return dim.n;
}


int Matrix::cols() {
    return dim.m;
}

/**
 *
 * @param rows
 * @param cols
 * @return Zero initialised rows x cols Matrix
 */

Matrix::Matrix(int rows, int cols) {
    dim = {rows,cols};
    values = (double * *) malloc(rows * sizeof(double*));
    for (int i = 0; i <rows ; ++i) {
        values[i] = (double *) calloc(cols, sizeof(double));
    }


}


Matrix Matrix::matmul(Matrix &m1, Matrix &m2) {
    assert(m1.dim.m == m2.dim.n);
    Matrix ret(m1.dim.n, m2.dim.m);

    for (int i = 0; i < m1.dim.n; ++i) {
        for (int j = 0; j < m2.dim.m; ++j) {
            for (int k = 0; k < m1.dim.m; ++k) {
                ret.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
}


Matrix Matrix::scale(double d, Matrix m) {
    Matrix mm = m.clone();
    for (int i = 0; i <m.dim.n ; ++i) {
        for (int j = 0; j <m.dim.m ; ++j) {
            m.values[i][j] *= d;
        }
    }
}

Matrix Matrix::clone() {
    Matrix ret(Matrix::clone2dArray(this->values));
    return ret;
}




double  **Matrix::clone2dArray(double **arr) {
    auto **ret = (double**)(malloc(sizeof(arr)));
    for (int i = 0; i <sizeof(arr) ; i+= sizeof(double*)) {
        auto *row= (double* )(malloc(sizeof(arr[i])));
        for (int j = 0; j < sizeof(arr[i]) ; j+= sizeof(double*)) {
             row[j]=arr[i][j];
        }

        ret[i] =row;
    }

    return ret;
}

std::string Matrix::toString() {
    return toString(*this);
}

std::string Matrix::toString(Matrix &m) {
    std::string s("[");
    for (int i = 0; i <m.dim.n ; ++i) {
        s.append("[");
        for (int j = 0; j <m.dim.m ; ++j) {
            if(j!=0){
             s.append(", ");
            }
            //std::cout<<m.values[i][j]<<" "<< std::endl;
            s.append(std::to_string(m.values[i][j]));
        }

        s.append("]");
        if(i!=m.dim.n-1) {s.append("\n");}
    }
    s.append("]");
    return s;
}

double *Matrix::getRow(int i) {
    return values[i];
}

double *Matrix::getCol(int i) {
    auto* col = (double*)malloc(sizeof(values));
    for (int j = 0; j < dim.n ; ++j) {
        col[j]=values[j][i];
    }
}

void Matrix::set(int row, int col, double d) {
    values[row][col]=d;
}

void Matrix::setRow(int i, double *rowValue) {
    assert(sizeof(rowValue)== sizeof(values[i]));
    values[i]=rowValue;

}

void Matrix::setCol(int i, const double *colValue) {
    assert(sizeof(colValue)== sizeof(values));
    for (int j = 0; j <dim.n ; ++j) {
        values[j][i]=colValue[j];
    }
}




