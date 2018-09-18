#include "application.h"

int main(int argc, char** argv) {
    auto app = Application::create();
    return app->run(argc, argv);
}
