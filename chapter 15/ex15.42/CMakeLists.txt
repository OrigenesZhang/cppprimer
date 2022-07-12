cmake_minimum_required(VERSION 3.21)
project(ex15_42)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex15_42 main.cpp TextQuery.cpp TextQuery.h Query_base.cpp Query_base.h Query.cpp Query.h)
