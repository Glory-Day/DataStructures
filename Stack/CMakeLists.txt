cmake_minimum_required(VERSION 3.27)
project(Stack VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Stack main.cpp
    stack.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)