cmake_minimum_required(VERSION 3.21)
project(ex14_18)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex14_18_1 a.cpp StrBlob.cpp StrBlob.h)
add_executable(ex14_18_2 b.cpp StrVec.cpp StrVec.h)
add_executable(ex14_18_3 c.cpp String.cpp String.h)
