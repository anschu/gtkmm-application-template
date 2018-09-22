cmake_minimum_required(VERSION 3.2)
project(GtkmmAppTemplate)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

option(USE_CCACHE "Want to use 'ccache'?" NO)
option(USE_CLANG_TIDY "Want to use 'clang-tidy'?" NO)
option(USE_IWYU "Want to use 'include-what-you-use'?" NO)

if(USE_CCACHE)
    find_program(CCACHE NAMES ccache sccache REQUIRED)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE})
endif()

if(USE_CLANG_TIDY)
    find_program(CLANG_TIDY NAMES clang-tidy REQUIRED)
    set(CLANG_TIDY_RUN ${CLANG_TIDY} "-checks=-*,bugprone-*,cppcoreguidelines-*")
endif()

if(USE_IWYU)
    find_program(IWYU NAMES include-what-you-use iwyu)
endif()

include(GlibUtils)

set(GENERATED_FILES_DIR ${CMAKE_BINARY_DIR}/generated)
configure_file(data/config.h.in ${GENERATED_FILES_DIR}/config.h)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
add_library(GTKMM INTERFACE IMPORTED)
set_property(TARGET GTKMM PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${GTKMM_INCLUDE_DIRS})
set_property(TARGET GTKMM PROPERTY INTERFACE_LINK_LIBRARIES ${GTKMM_LIBRARIES})
set_property(TARGET GTKMM PROPERTY INTERFACE_COMPILE_OPTIONS ${GTKMM_CFLAGS_OTHER})

add_subdirectory(src)
#add_subdirectory(test)
