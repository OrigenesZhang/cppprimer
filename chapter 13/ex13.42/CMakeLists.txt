cmake_minimum_required(VERSION 3.21)
project(ex13_42)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex13_42 main.cpp TextQuery.cpp TextQuery.h ../ex13.40/StrVec.cpp ../ex13.40/StrVec.h)
