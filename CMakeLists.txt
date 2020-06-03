cmake_minimum_required(VERSION 3.15)
project(NeuroNet)

set(CMAKE_CXX_STANDARD 14)

add_executable(NeuroNet main.cpp Dimension.h Matrix.cpp Matrix.h Util.cpp Util.h Tests/Test.cpp Tests/Test.h LinkedList.cpp LinkedList.h GenericList.h Tests/MatrixTest.cpp Tests/MatrixTest.h)