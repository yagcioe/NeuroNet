//
// Created by Oemer on 31.05.2020.
//


#include <assert.h>
#include "Matrix.h"
template <class T>
Matrix<T>::Matrix( T *arrOfValues){

    dim.n= sizeof(arrOfValues);
    dim.m= sizeof(arrOfValues[0]);
    //checke ob Eingabearray korrekt geformt ist
    for (int i = 1; i <dim.n ; ++i) {
        assert( (sizeof(arrOfValues[i])==dim.m));
    }

}
template <class T>
T *Matrix<T>::get(int n, int m) {
    return values[n][m];
}


template <class T>
Dimension Matrix<T>::getDim(){
    return dim;
}

//TODO
template<class T>
T *Matrix<T>::getValueArray() {
    return values;
}

//TODO
template<class T>
Matrix<T> Matrix<T>::operator*(Matrix &m) {
    return Matrix(nullptr);
}

template<class T>
int Matrix<T>::rows() {
    return dim.n;
}

template<class T>
int Matrix<T>::cols() {
    return dim.m;
}



