cmake_minimum_required(VERSION 3.21)
project(ex15_29)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex15_29 main.cpp ../ex15.15/Bulk_quote.cpp ../ex15.15/Disc_quote.cpp ../ex15.15/Quote.cpp)
