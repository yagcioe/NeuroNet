#include <iostream>
#include "Matrix.h"

int main() {
    Matrix m(2,3);
    double s[]= {1.2,3.4};
    m.setRow(0,s);
    std::string str("test");
    std::cout<< m.toString();

}