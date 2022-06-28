cmake_minimum_required(VERSION 3.21)
project(ex14_16)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex14_16_1 a.cpp StrBlob.cpp StrBlob.h c.cpp)
add_executable(ex14_16_2 b.cpp StrVec.cpp StrVec.h)
add_executable(ex14_16_3 c.cpp String.cpp String.h)