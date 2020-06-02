cmake_minimum_required(VERSION 3.15)
project(NeuroNet)

set(CMAKE_CXX_STANDARD 14)

add_executable(NeuroNet main.cpp Node.h Dimension.h Matrix.cpp Matrix.h Util.cpp Util.h Test.cpp Test.h LinkedList.cpp LinkedList.h)