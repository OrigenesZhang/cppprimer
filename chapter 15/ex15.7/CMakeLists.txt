cmake_minimum_required(VERSION 3.21)
project(ex15_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex15_7 main.cpp Bulk_quote_limited.cpp Bulk_quote_limited.h ../ex15.5/Quote.cpp ../ex15.5/Quote.h)
