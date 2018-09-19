#ifndef APPLICATION_H
#define APPLICATION_H

#include <gtkmm/application.h>

#include "window.h"

class Application : public Gtk::Application {
    public:
    virtual ~Application() override;

    static Glib::RefPtr<Application> create();

    private:
    Application();

    Window* create_window();

    void on_activate() override;
    void on_startup() override;
    void on_hide_window(Gtk::Window* window);
};

#endif  // APPLICATION_H
