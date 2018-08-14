file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(ut ${SRCS})

TARGET_LINK_LIBRARIES(ut
    libbar
    libgtest
    libgmock
)

add_test(NAME ut
         COMMAND ut)

