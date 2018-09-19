#include "application.h"
#include <glibmm.h>

int main(int argc, char** argv) {
    Glib::setenv("GESETTINGS_SCHEMA_DIR", ".", false);
    auto app = Application::create();
    return app->run(argc, argv);
}
