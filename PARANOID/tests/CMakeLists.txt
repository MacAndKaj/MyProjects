file(GLOB SRCS *.cpp)
find_package(Threads REQUIRED)

add_executable(tests ${SRCS})
include_directories("${source_dir}/googletest/include"
        "${source_dir}/googlemock/include"
        )
include_directories ("${PROJECT_SOURCE_DIR}/src/include")

################################
find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
endif ()
enable_testing()
target_link_libraries(tests gtest gmock gtest_main MyLib pthread)

install(TARGETS tests DESTINATION build)