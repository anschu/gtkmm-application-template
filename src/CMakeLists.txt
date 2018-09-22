add_executable(${PROJECT_NAME}
    main.cpp
    application.cpp
    window.cpp
    preferences.cpp
    ${GENERATED_FILES_DIR}/resources.c
    )

target_link_libraries(${PROJECT_NAME}
    GTKMM
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${GENERATED_FILES_DIR})

compile_resources(
    ${GENERATED_FILES_DIR}/resources.c
    ${CMAKE_SOURCE_DIR}/data/
    app.gresource.xml
    window.glade
    headerbar.glade
    menu.glade
    preferences.glade
    )

compile_schemas(
    ${CMAKE_SOURCE_DIR}/data/
    org.gtkmm.template.gschema.xml
    )

if(USE_CLANG_TIDY)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_CLANG_TIDY ${CLANG_TIDY_RUN})
endif()

if(USE_IWYU)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${IWYU})
endif()
