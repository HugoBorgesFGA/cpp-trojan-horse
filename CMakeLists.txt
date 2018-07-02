cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -O0 -ggdb -g3")

project (TrojanServer)

include_directories(inc)

add_subdirectory(third_party)
add_subdirectory(src)

