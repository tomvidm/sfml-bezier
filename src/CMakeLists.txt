set(SOURCES
    main.cpp
    primitives/LineStrip.cpp
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${sfmlprimitives_INCLUDE_DIR}
)

add_executable(sfml-primitives
    ${SOURCES}
)

target_link_libraries(sfml-primitives
    ${SFML_LIBRARIES}
)