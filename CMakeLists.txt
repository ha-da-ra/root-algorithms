cmake_minimum_required(VERSION 3.12)
project(root_algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(root_algorithms main.cpp AlgorithmResult.hpp AlgorithmResult.cpp)
target_include_directories(root_algorithms PRIVATE include)