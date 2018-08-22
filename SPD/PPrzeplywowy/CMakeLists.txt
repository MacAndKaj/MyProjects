cmake_minimum_required(VERSION 3.8)
project(PPrzeplywowy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Zadanie.cpp Zadanie.h Funkcje.cpp Funkcje.h ZbiorZadan.cpp ZbiorZadan.h Maszyna.cpp Maszyna.h)
add_executable(PPrzeplywowy ${SOURCE_FILES})