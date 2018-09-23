add_executable(${PROJECT_NAME}
    main.cpp
    application.cpp
    window.cpp
    preferences.cpp
    ${GENERATED_DATA_DIR}/resources.c
    )

target_link_libraries(${PROJECT_NAME}
    GTKMM
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${GENERATED_SOURCES_DIR})

compile_resources(
    ${GENERATED_DATA_DIR}/resources.c
    window.glade
    headerbar.glade
    menu.glade
    preferences.glade
    )

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
