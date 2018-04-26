cmake_minimum_required(VERSION 3.0)

project(sfml-primitives)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

find_package(SFML 2 REQUIRED graphics window system)

set(sfmlprimitives_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(sfmlprimitives_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(sfmlprimitives_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_subdirectory(external/googletest)
add_subdirectory(src)
add_subdirectory(test)


