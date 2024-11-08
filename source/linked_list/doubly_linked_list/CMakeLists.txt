cmake_minimum_required(VERSION 3.8)

project(doubly_linked_list VERSION 0.1.0 LANGUAGES CXX)

file(GLOB SOURCES *.cpp)

add_library(${PROJECT_NAME} OBJECT ${SOURCES})

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)