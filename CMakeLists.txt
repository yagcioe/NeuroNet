cmake_minimum_required(VERSION 3.15)
project(NeuroNet)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")

add_executable(NeuroNet main.cpp Math/LinAlg/Dimension.h Math/LinAlg/Matrix.cpp Math/LinAlg/Matrix.h Tests/Test.cpp Tests/Test.h Util/LinkedList.cpp Util/LinkedList.h Util/GenericList.h Tests/MatrixTest.cpp Tests/MatrixTest.h Graph/Graph.cpp Graph/Graph.h Graph/Node.cpp Graph/Node.h Math/Functions/IFunction.h Math/Functions/Glocke/Gauss.cpp Math/Functions/Glocke/Gauss.h Math/Functions/Glocke/Multiquadrate.cpp Math/Functions/Glocke/Multiquadrate.h Math/Functions/LinearFunction.cpp Math/Functions/LinearFunction.h Math/Functions/LimitedLinearFunction.cpp Math/Functions/LimitedLinearFunction.h Math/Functions/BinaryFunction.cpp Math/Functions/BinaryFunction.h Math/LinAlg/GenericMatrix.cpp Math/LinAlg/GenericMatrix.h Math/LinAlg/IGenericMatrixValue.h Util/TestClass.cpp Util/TestClass.h)