configure_file(desktop.in ${GENERATED_DATA_DIR}/${PROJECT_NAME}.desktop)
configure_file(gresource.xml.in ${GENERATED_DATA_DIR}/${PROJECT_NAME}.gresource.xml)
configure_file(gschema.xml.in ${GENERATED_DATA_DIR}/${APPLICATION_ID}.gschema.xml)

compile_schemas(
    ${GENERATED_DATA_DIR}/${APPLICATION_ID}.gschema.xml
    )
