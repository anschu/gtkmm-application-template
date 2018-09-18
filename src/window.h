#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>

class Window : public Gtk::ApplicationWindow {
    public:
    Window(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~Window();

    static Window* create();

    private:
    Glib::RefPtr<Gtk::Builder> builder;
};

#endif  // WINDOW_H
