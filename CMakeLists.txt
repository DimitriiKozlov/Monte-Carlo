cmake_minimum_required(VERSION 3.3)
project(CA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp test.cpp MonteCarlo.cpp MonteCarlo.h)
add_executable(CA ${SOURCE_FILES})