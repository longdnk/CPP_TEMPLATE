cmake_minimum_required(VERSION 3.24)
project(CPP_TEST)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops -unroll-loops)
add_executable(CPP_TEST main.cpp header/Student.cpp header/Student.h color.cpp sol.cpp)