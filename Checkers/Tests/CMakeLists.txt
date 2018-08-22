add_executable(Tests
        ButtonTests.cpp
        GameTests.cpp
        MainWindowTests.cpp
        PieceTests.cpp
        PlayerTests.cpp
)

target_link_libraries(Tests
        gtest_main
)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/Tests
)