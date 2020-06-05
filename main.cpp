#include <iostream>
#include "Tests/MatrixTest.h"
#include "Util/TestClass.h"

int main() {
 //test();
 TestClass *t= new TestClass(12);
 TestClass *t2 = new TestClass(42);
 std::cout<<t->d<<"&"<<t2->d<<"\n";
 *t= *t2;
 std::cout<<t->d<<"&"<<t2->d<<"\n";
 t2->d=13;
 std::cout<<t->d<<"&"<<t2->d<<"\n";
 return 0;
}