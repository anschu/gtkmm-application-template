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

void Application::on_startup()
{
    Gtk::Application::on_startup();

    add_action("preferences", sigc::mem_fun(*this, &ExampleApplication::on_action_preferences));
    add_action("quit", sigc::mem_fun(*this, &ExampleApplication::on_action_quit));
    set_accel_for_action("app.quit", "<Ctrl>Q");

    auto refBuilder = Gtk::Builder::create();
    try
    {
      refBuilder->add_from_resource("/org/gtkmm/exampleapp/app_menu.ui");
    }
    catch (const Glib::Error& ex)
    {
      std::cerr << "ExampleApplication::on_startup(): " << ex.what() << std::endl;
      return;
    }

    auto object = refBuilder->get_object("appmenu");
    auto app_menu = Glib::RefPtr<Gio::MenuModel>::cast_dynamic(object);
    if (app_menu)
      set_app_menu(app_menu);
    else
      std::cerr << "ExampleApplication::on_startup(): No \"appmenu\" object in app_menu.ui"
                << std::endl;
}

void Application::on_hide_window(Gtk::Window *window) {
    delete window;
}
