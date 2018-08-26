include_directories(include)
file(GLOB src_files
        sources/Buttons/*.cpp
        sources/Scenario/*.cpp
        sources/Workers/*.cpp
        sources/*.cpp)
add_library(MyLib ${src_files})

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} MyLib)
find_package(SFML 2.5 REQUIRED network audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

