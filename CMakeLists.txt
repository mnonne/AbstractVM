cmake_minimum_required(VERSION 3.0)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

add_executable(UT
        unittests/main.cpp
        unittests/test_int8.cpp
        unittests/test_operands.cpp
        unittests/test_operands2.cpp
        unittests/test_stack.cpp
        src/IOperand.h
        src/Operand.h
        src/OperandFactory.cpp
        src/OperandFactory.h
        src/OperandFactory.h
        src/OperandSizeException.cpp
        src/OperandStack.cpp
        src/OperandStack.h
        src/StackException.cpp
        src/StackException.h
)

target_link_libraries(UT gtest)

add_executable(AbstractVM
        src/main.cpp
        src/IOperand.h
        src/Operand.h
        src/OperandFactory.cpp
        src/OperandFactory.h
        src/OperandFactory.h
        src/OperandSizeException.cpp
        src/OperandStack.cpp
        src/OperandStack.h
        src/StackException.cpp
        src/StackException.h
        src/Parser.cpp src/Parser.h src/Lexer.cpp src/Lexer.h src/LexicalException.cpp src/LexicalException.h)
