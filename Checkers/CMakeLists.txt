cmake_minimum_required(VERSION 3.10)
project(Checkers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

set(EXECUTABLE_NAME "Checkers")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(inc)

set(SOURCES src/Button.cpp
            src/MainWindow.cpp
            src/Game.cpp
            src/Piece.cpp
            src/Player.cpp)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
enable_testing()
add_subdirectory(Tests)

add_executable(${EXECUTABLE_NAME}
        main.cpp
        ${SOURCES}
        bin/icon.png
        bin/Pacific_Again.ttf)
target_link_libraries(${EXECUTABLE_NAME} gtest)
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

