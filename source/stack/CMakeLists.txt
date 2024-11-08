cmake_minimum_required(VERSION 3.8)

project(stack VERSION 0.1.0 LANGUAGES CXX)

file(GLOB SOURCES *.cpp)

add_library(${PROJECT_NAME} OBJECT ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror)