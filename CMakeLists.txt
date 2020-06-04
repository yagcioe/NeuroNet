cmake_minimum_required(VERSION 3.15)
project(NeuroNet)

set(CMAKE_CXX_STANDARD 14)

add_executable(NeuroNet main.cpp Util/Dimension.h Util/Matrix.cpp Util/Matrix.h Tests/Test.cpp Tests/Test.h Util/LinkedList.cpp Util/LinkedList.h Util/GenericList.h Tests/MatrixTest.cpp Tests/MatrixTest.h Graph.cpp Graph.h Node.cpp Node.h Functions/IFunction.h Functions/Glocke/Gauss.cpp Functions/Glocke/Gauss.h Functions/Glocke/Multiquadrate.cpp Functions/Glocke/Multiquadrate.h Functions/LinearFunction.cpp Functions/LinearFunction.h Functions/LimitedLinearFunction.cpp Functions/LimitedLinearFunction.h Functions/BinaryFunction.cpp Functions/BinaryFunction.h)