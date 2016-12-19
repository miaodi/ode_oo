cmake_minimum_required(VERSION 3.6)
project(ode_oo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp system/AbstractOdeSystem.cpp system/AbstractOdeSystem.h system/AbstractSecondOrderOdeSystem.cpp system/AbstractSecondOrderOdeSystem.h solver/AbstractOdeSolver.cpp solver/AbstractOdeSolver.h system/AbstractFirstOrderOdeSystem.cpp system/AbstractFirstOrderOdeSystem.h solver/AbstractFirstOrderOdeSolver.cpp solver/AbstractFirstOrderOdeSolver.h)
add_executable(ode_oo ${SOURCE_FILES})