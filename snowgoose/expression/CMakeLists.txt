cmake_minimum_required(VERSION 3.9)
project(expression)

set(CMAKE_CXX_STANDARD 11)

add_executable(expression
        algder.hpp
        algorithm.hpp
        expr.hpp
        node.hpp
        testexpr.cpp
        utils.h)
