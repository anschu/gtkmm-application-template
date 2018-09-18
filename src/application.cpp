#include "application.h"

#include <iostream>

Application::Application() = default;

Application::~Application() = default;

Glib::RefPtr<Application> Application::create() {
    return Glib::RefPtr<Application>(new Application());
}

Window *Application::create_window() {
    auto window = Window::create();
    add_window(*window);

    window->signal_hide().connect(
        sigc::bind<Gtk::Window *>(sigc::mem_fun(*this, &Application::on_hide_window), window));

    return window;
}

void Application::on_activate() {
    try {
        auto window = create_window();
        window->present();
    } catch (const Glib::Error &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    }
}

void Application::on_hide_window(Gtk::Window *window) {
    delete window;
}
