#include <glibmm.h>

#include <iostream>

#include "application.h"
#include "config.h"

int main(int argc, char** argv) {
    Glib::setenv("GSETTINGS_SCHEMA_DIR", getGeneratedGSchemaDirectory(), false);
    auto app = Application::create();
    return app->run(argc, argv);
}
