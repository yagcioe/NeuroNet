#include <iostream>
#include "Matrix.h"

int main() {
    Matrix m(2,3);
    double s[]= {1.2,3.4,12};
    m.setRow(0,s);
    double d[] = {7.4,12,66.6};
    m.setRow(1,d);
    Matrix m2(3,1);
    double dd[]= {4,3.3,7};
    m2.setCol(0,3,dd);
    std::string str("test");
    Matrix c =Matrix::matmul(m,m2);
    Matrix de = m*m2;
    std::cout<<"m"<< m.toString()<<std::endl<<"m2"<<m2.toString()<<std::endl<<"c"<<c.toString()<<"d"<< de.toString();

}