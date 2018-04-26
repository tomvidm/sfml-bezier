project(sfml-bezier-tests)

set(TEST_SOURCES
    TrivialTest.cpp
    math/MathTests.cpp
)

include_directories(
    ${sfmlbezier_INCLUDE_DIR}
    ${gtest_INCLUDE_DIR}
)

message(STATUS ${sfmlbezier_INCLUDE_DIR})

add_executable(sfml-bezier-tests
    ${TEST_SOURCES}
)

target_link_libraries(sfml-bezier-tests
    gtest
    gtest_main
)