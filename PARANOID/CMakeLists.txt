cmake_minimum_required(VERSION 3.10)
project(PARANOID)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME "PARANOID")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
add_subdirectory(src)

add_subdirectory(tests)

if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

    # list of files for which we add a copy rule
    set(data_SHADOW Resoures/Pacific_Again.ttf Resoures/icon.png)

    foreach(item IN LISTS data_SHADOW)
        message(STATUS ${item})
        add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
        )
    endforeach()
endif()

# files are only copied if a target depends on them
add_custom_target(data-target ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/yourimg.png")