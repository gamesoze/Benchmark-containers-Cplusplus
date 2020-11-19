cmake_minimum_required(VERSION 3.17)
project(benchmark_c)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-O3")

add_subdirectory(submodule/googletest)
add_subdirectory(submodule/benchmark)

add_executable(benchmark_c main.cpp vector.h MyClass.h list.h deque.h set.h)

target_link_libraries(benchmark_c benchmark)