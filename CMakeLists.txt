cmake_minimum_required(VERSION 3.16.3)
project(wks)

# Adding dependencies
add_subdirectory(deps/libzmq)
add_subdirectory(deps/cppzmq)
add_subdirectory(deps/jsoncpp)
add_subdirectory(deps/RhIO)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC RhIO)