#include "window.h"

#include <iostream>

Window::Window(Gtk::ApplicationWindow::BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
    : Gtk::ApplicationWindow(cobject), builder(builder) {
}

Window::~Window() {
}

Window* Window::create() {
    auto builder = Gtk::Builder::create_from_resource("/window/window.glade");

    Window* window = nullptr;
    builder->get_widget_derived("window", window);
    if (!window)
        throw std::runtime_error("No \"window\" object in window.ui");

    return window;
}
