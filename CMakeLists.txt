cmake_minimum_required(VERSION 3.8)

project(
    DataStructure 
    VERSION 0.1.0
    DESCRIPTION "Data Structures in Modern C++" 
    LANGUAGES CXX)

add_subdirectory(source)
add_subdirectory(test)

set(LIBRARIES 
    stack 
    queue
    linked_list
    heap
    tree
    hash_table)

foreach(LIBRARY ${LIBRARIES})
    set(LIBRARY_OBJECT ${LIBRARY_OBJECT} $<TARGET_OBJECTS:${LIBRARY}>)
endforeach()

add_library(${PROJECT_NAME} STATIC ${LIBRARY_OBJECT})