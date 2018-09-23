#include <glibmm.h>

#include <iostream>

#include "application.h"
#include "projectdefinitions.h"

int main(int argc, char** argv) {
    Glib::setenv("GSETTINGS_SCHEMA_DIR", projectdefinitions::getGeneratedDataDirectory(), false);
    auto app = Application::create();
    return app->run(argc, argv);
}
