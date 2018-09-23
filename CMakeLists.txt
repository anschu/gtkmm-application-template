cmake_minimum_required(VERSION 3.2)

project(GtkmmApplicationTemplate VERSION 1.0)

set(APPLICATION_ID "de.anschu.${PROJECT_NAME}")
string(REPLACE "." "/" APPLICATION_PREFIX "/${APPLICATION_ID}/")

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)
include(GlibUtils)
include(InstallScript)

set(GENERATED_FILES_DIR ${CMAKE_BINARY_DIR}/generated)
set(GENERATED_SOURCES_DIR ${GENERATED_FILES_DIR}/src)
set(GENERATED_DATA_DIR ${GENERATED_FILES_DIR}/data)

configure_file(cmake/projectdefinitions.h.in ${GENERATED_SOURCES_DIR}/projectdefinitions.h)

find_package(GTKMM)

add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(test)

install(FILES uninstall.sh DESTINATION ${CMAKE_BINARY_DIR} PERMISSIONS OWNER_EXECUTE OWNER_READ OWNER_WRITE)
