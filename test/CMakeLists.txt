project(sfml-bezier-tests)

set(TEST_SOURCES
    TrivialTest.cpp
)

include_directories(
    ${gtest_INCLUDE_DIR}
)

add_executable(sfml-bezier-tests
    ${TEST_SOURCES}
)

target_link_libraries(sfml-bezier-tests
    gtest
    gtest_main
)