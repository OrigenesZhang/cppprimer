cmake_minimum_required(VERSION 3.21)
project(ex16_29)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex16_29 main.cpp Blob.h ../ex16.28/SharedPtr.h ../ex16.28/Delete.h)
