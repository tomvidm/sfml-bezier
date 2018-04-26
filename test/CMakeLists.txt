project(sfml-primitives-tests)

set(TEST_SOURCES
    TrivialTest.cpp
    math/MathTests.cpp
)

include_directories(
    ${sfmlprimitives_INCLUDE_DIR}
    ${gtest_INCLUDE_DIR}
)

message(STATUS ${sfmlprimitives_INCLUDE_DIR})

add_executable(sfml-primitives-tests
    ${TEST_SOURCES}
)

target_link_libraries(sfml-primitives-tests
    gtest
    gtest_main
)