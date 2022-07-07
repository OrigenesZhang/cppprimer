cmake_minimum_required(VERSION 3.21)
project(ex15_16)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex15_16 main.cpp Limit_quote.cpp Limit_quote.h ../ex15.15/Disc_quote.cpp ../ex15.15/Disc_quote.h ../ex15.15/Quote.cpp ../ex15.15/Quote.h)
