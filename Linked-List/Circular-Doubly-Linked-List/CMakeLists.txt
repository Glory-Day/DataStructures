cmake_minimum_required(VERSION 3.27)
project(Circular-Doubly-Linked-List VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Circular-Doubly-Linked-List main.cpp node.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)