add_executable(${PROJECT_NAME}
    main.cpp
    application.cpp
    window.cpp
    settings.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/resources.c
    )

target_link_libraries(${PROJECT_NAME}
    GTKMM
    )

compile_resources(
    ${CMAKE_CURRENT_BINARY_DIR}/resources.c
    ${CMAKE_SOURCE_DIR}/res/
    app.gresource.xml
    window/window.glade
    )

compile_schemas(
    ${CMAKE_SOURCE_DIR}/res/
    app.gschema.xml
    )

if(USE_CLANG_TIDY)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_CLANG_TIDY ${CLANG_TIDY_RUN})
endif()

if(USE_IWYU)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${IWYU})
endif()
