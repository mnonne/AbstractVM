cmake_minimum_required(VERSION 3.13)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

add_executable(AbstractVM
        unittests/main.cpp
        unittests/test_int8.cpp
        unittests/test_operands.cpp
        src/IOperand.h
        src/Operand.h
        src/OperandFactory.cpp
        src/OperandFactory.h
        src/OperandFactory.h src/OperandSizeException.cpp)

target_link_libraries(AbstractVM gtest)