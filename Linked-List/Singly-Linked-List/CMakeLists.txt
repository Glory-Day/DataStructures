cmake_minimum_required(VERSION 3.27)
project(Singly-Linked-List VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Singly-Linked-List main.cpp
    singly_linked_list.cpp
    node.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)