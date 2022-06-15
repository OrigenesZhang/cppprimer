cmake_minimum_required(VERSION 3.21)
project(ex12_32)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex12_32 main.cpp text_query.cpp text_query.h ../ex12.22/str_blob.cpp ../ex12.22/str_blob.h)
