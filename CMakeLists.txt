cmake_minimum_required(VERSION 3.1)

project(esrocos-tools-transformer_python)

set(CMAKE_CXX_FLAGS)

add_definitions(-Wall -Wno-unknown-pragmas)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
