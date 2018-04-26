set(SOURCES
    main.cpp
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${sfmlbezier_INCLUDE_DIR}
)

add_executable(sfml-bezier
    ${SOURCES}
)

target_link_libraries(sfml-bezier
    ${SFML_LIBRARIES}
)