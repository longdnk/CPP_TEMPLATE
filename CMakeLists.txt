cmake_minimum_required(VERSION 3.24)
project(CPP_TEST)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_TEST main.cpp header/Student.cpp header/Student.h)
