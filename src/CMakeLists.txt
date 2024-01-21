
cmake_minimum_required(VERSION 3.22)
project(guidecraft)

set(CMAKE_CXX_STANDARD 17)
#add_compile_options(--std=c++17)

add_compile_options(-fpic)
add_compile_options(-Wall)

add_subdirectory (br)
