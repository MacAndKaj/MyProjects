cmake_minimum_required(VERSION 3.5)
project(Zad1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Zadanie.cpp Zadanie.h ZbiorZadan.cpp ZbiorZadan.h Wczytywacz.cpp Wczytywacz.h)
add_executable(Zad1 ${SOURCE_FILES})