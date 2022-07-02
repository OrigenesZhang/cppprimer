cmake_minimum_required(VERSION 3.21)
project(ex14_32)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex14_32 main.cpp StrBlobPtr_Ptr.cpp StrBlobPtr_Ptr.h ../ex14.30/StrBlob.cpp ../ex14.30/StrBlob.h)
