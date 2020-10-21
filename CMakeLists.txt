cmake_minimum_required(VERSION 3.16)
project(Programmierung)

set(CMAKE_CXX_STANDARD 14)

add_executable(Programmierung main.cpp RootDeterminationAlgorithm.cpp Bisection.cpp RegulaFalsi.cpp
        AlgorithmTester.cpp TestableExample.cpp SecantMethode.cpp)