cmake_minimum_required(VERSION 3.20)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_CXX_STANDARD 20)



project(step0_repl)

add_executable(step0_repl step0_repl.cpp)
target_link_libraries(step0_repl readline)
