file(GLOB SRCS UT/*.cpp)
find_package(Threads REQUIRED)
include_directories ("${PROJECT_SOURCE_DIR}/src/include")

add_executable(tests ${SRCS})
include_directories("${source_dir}/googletest/include"
        "${source_dir}/googlemock/include"
        )

################################
find_package(SFML 2.5 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

find_package(GTest REQUIRED)

if (GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
endif ()
enable_testing()
target_link_libraries(tests gtest gmock gtest_main MyLib pthread ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

install(TARGETS tests DESTINATION build)