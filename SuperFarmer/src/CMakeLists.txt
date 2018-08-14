set(Main_SRCS
    main.cpp
)

add_executable(superFarm
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(superFarm
	libbar
)

# install(TARGETS superFarm DESTINATION bin)

