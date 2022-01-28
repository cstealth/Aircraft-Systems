cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project ("AeroSys" VERSION 0.1)

add_subdirectory(lib)
add_subdirectory(src)