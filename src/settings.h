#ifndef SETTINGS_H
#define SETTINGS_H

#include <gtkmm/dialog.h>
#include <gtkmm/builder.h>
#include <gtkmm/switch.h>
#include <giomm/settings.h>

class Settings : public Gtk::Dialog {
    public:
    Settings(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    static Settings* create(Gtk::Window& parent);

private:
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gio::Settings> settings;
    Gtk::Switch* switchButton;
};

#endif  // SETTINGS_H
