cmake_minimum_required(VERSION 3.15)
project(lob_matching_engine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

add_executable(lob_sim src/main.cpp)
target_include_directories(lob_sim PRIVATE include)