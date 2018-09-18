add_executable(${PROJECT_NAME}
    main.cpp
    application.cpp
    window.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/resources.c
    )

target_link_libraries(${PROJECT_NAME}
    GTKMM
    )

set(RESOURCES_DIR ${CMAKE_SOURCE_DIR}/res/)
set(RESOURCES
    ${RESOURCES_DIR}/app.gresource.xml
    ${RESOURCES_DIR}/window/window.glade
    )

add_custom_command(
    OUTPUT resources.c
    WORKING_DIRECTORY ${RESOURCES_DIR}
    COMMAND glib-compile-resources --target=${CMAKE_CURRENT_BINARY_DIR}/resources.c --generate-source app.gresource.xml
    DEPENDS ${RESOURCES}
    COMMENT "Generating resources.c..."
    )

if(USE_CLANG_TIDY)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_CLANG_TIDY ${CLANG_TIDY_RUN})
endif()

if(USE_IWYU)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${IWYU})
endif()
