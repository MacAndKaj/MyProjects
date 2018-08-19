include_directories(include)
add_library(MyLib
        sources/Buttons/LetterButton.cpp
        sources/Buttons/NormalButton.cpp
        sources/MainWindow.cpp)
add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} MyLib)
find_package(SFML 2.5 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()