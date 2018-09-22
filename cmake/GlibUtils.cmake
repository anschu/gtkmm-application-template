macro(compile_resources OUTPUT WORK_DIR GRESOURCE_XML)
    find_program(GLIB_RESOURCE_COMPILER NAMES glib-compile-resources REQUIRED)

    if(${ARGC} GREATER 3)
        foreach(arg IN ITEMS ${ARGN})
            string(CONCAT RESOURCE ${WORK_DIR}/ui/ ${arg})
            list(APPEND RESOURCES ${RESOURCE})
        endforeach()
    endif()

    add_custom_command(
        OUTPUT ${OUTPUT}
        WORKING_DIRECTORY ${WORK_DIR}
        COMMAND ${GLIB_RESOURCE_COMPILER} --target=${OUTPUT} --generate-source ${GRESOURCE_XML}
        DEPENDS ${WORK_DIR}/${GRESOURCE_XML} ${RESOURCES}
        COMMENT "Generating ${OUTPUT}..."
        )

endmacro()

macro(compile_schemas WORK_DIR GSCHEMA_XML)
    find_program(GLIB_SCHEMA_COMPILER NAMES glib-compile-schemas REQUIRED)

    if(${ARGC} GREATER 2)
        foreach(arg IN ITEMS ${ARGN})
            string(CONCAT SCHEMA ${WORK_DIR} ${arg})
            list(APPEND SCHEMAS ${SCHEMA})
        endforeach()
    endif()

    set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/generated/glib-2.0/schemas)
    set(OUTPUT ${OUTPUT_DIR}/gschemas.compiled)
    add_custom_command(
        OUTPUT ${OUTPUT}
        WORKING_DIRECTORY ${WORK_DIR}
        COMMAND mkdir -p ${OUTPUT_DIR}
        COMMAND ${GLIB_SCHEMA_COMPILER} --strict --dry-run --schema-file=${GSCHEMA_XML}
        COMMAND ${GLIB_SCHEMA_COMPILER} --schema-file=${GSCHEMA_XML} --targetdir=${OUTPUT_DIR}
        DEPENDS ${WORK_DIR}/${GSCHEMA_XML} ${SCHEMAS}
        COMMENT "Generating ${OUTPUT}..."
        )
    add_custom_target(GSCHEMA ALL DEPENDS ${OUTPUT})
endmacro()
