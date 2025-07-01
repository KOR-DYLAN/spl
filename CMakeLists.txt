cmake_minimum_required(VERSION 3.10.0)

project(spl)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(source)
add_subdirectory(test)
