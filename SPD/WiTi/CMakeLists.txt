cmake_minimum_required(VERSION 3.8)
project(WiTi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Zadanie.cpp Zadanie.h ZbiorZadan.cpp ZbiorZadan.h)
add_executable(WiTi ${SOURCE_FILES})