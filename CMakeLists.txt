cmake_minimum_required(VERSION 3.0)

project(sfml-bezier)

add_subdirectory(external/googletest)
add_subdirectory(src)
add_subdirectory(test)

set("sfmlbezier_INCLUDE_DIR" ${CMAKE_CURRENT_SOURCE_DIR/include})
set("sfmlbezier_SRC_DIR" ${CMAKE_CURRENT_SOURCE_DIR/src})

