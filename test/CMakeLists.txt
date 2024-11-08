cmake_minimum_required(VERSION 3.8)

project(test VERSION 0.1.0 LANGUAGES CXX)

file(GLOB TEST_FILES_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
foreach(TEST_FILE_PATH ${TEST_FILES_PATHS})
    message("[test] Found Test File: ${TEST_FILE_PATH}")

    get_filename_component(FILE_NAME ${TEST_FILE_PATH} NAME)
    get_filename_component(BASE_NAME ${TEST_FILE_PATH} NAME_WE)
    add_executable(${BASE_NAME}_test ${FILE_NAME})

    message("[test] Add Excutable Test File: ${BASE_NAME}_test\n")
endforeach()

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/source)