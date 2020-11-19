cmake_minimum_required(VERSION 3.17)
project(benchmark_c)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-O3")

add_subdirectory(benchmark)

add_executable(benchmark_c main.cpp ben_vector.h MyClass.h)

target_link_libraries(benchmark_c benchmark)