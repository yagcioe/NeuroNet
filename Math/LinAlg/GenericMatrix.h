//
// Created by Oemer on 05.06.2020.
//

#ifndef NEURONET_GENERICMATRIX_H
#define NEURONET_GENERICMATRIX_H

#include "Matrix.h"
#include "Test.h"
#include "IGenericMatrixValue.h"


template<class T>
class GenericMatrix {
    Matrix *m;

    GenericMatrix(int rows, int cols, T *values[]) {
        static_assert(std::is_base_of<IGenericMatrixValue, T>::value,
                      "Template Type must implement IGenericMatrixValue");
        m = new Matrix(rows, cols, values);
    }

    GenericMatrix(int rows, int cols) {
        static_assert(std::is_base_of<IGenericMatrixValue, T>::value,
                      "Template Type must implement IGenericMatrixValue");
        m = new Matrix(rows, cols);
    }

    ~GenericMatrix() {
        delete m;
    }

    GenericMatrix *scale(double d, GenericMatrix o) {
        Matrix *mm = m->clone();
        for (int i = 0; i < o.m.rows(); ++i) {
            for (int j = 0; j < o.m.cols(); ++j) {
                T *t = m->get(i, j);
                mm->set(i, j, *t * d);
            }
        }
        return mm;
    }

    GenericMatrix<T> matmul(GenericMatrix<T> &m1, GenericMatrix<T> &m2) {
        assert(m1.dim.m == m2.dim.n);
        Matrix ret(m1.dim.n, m2.dim.m);

        for (int i = 0; i < m1.dim.n; ++i) {
            for (int j = 0; j < m2.dim.m; ++j) {
                for (int k = 0; k < m1.dim.m; ++k) {
                    T *t1 = m1.get(i, j);
                    T *t2 = m1.get(i, k);
                    T *t3 = m2.get(k, j);
                    ret.set(i, j, *t1 + *t2 * *t3);
                }
            }
        }
        return ret;
    }

    GenericMatrix<T> operator*(GenericMatrix<T> &o) {
        return matmul(*this, o);
    }


    GenericMatrix *clone() {

        return new GenericMatrix(m->rows(), m->cols(), clone2dArray(m->rows(), m->cols(), this->values));

    }

    //TODO clone?
    T **clone2dArray(int rows, int cols, T *arr[]) {
        auto ret = new T *[rows * cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                //elements must be primitive or = must be overridden
                *ret[j * i] = *arr[i * j];
            }
        }

        return ret;
    }

    std::string toString() {
        std::string s("[");
        for (int i = 0; i < m->rows(); ++i) {
            s.append("[");
            for (int j = 0; j < m->cols(); ++j) {
                if (j != 0) {
                    s.append(", ");
                }
                T *t = m->get(i, j);
                s.append(t->toString());
            }

            s.append("]");
            if (i != m->rows() - 1) { s.append("\n"); }
        }
        s.append("]");
        return s;
    }
};


#endif //NEURONET_GENERICMATRIX_H
