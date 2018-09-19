#include "settings.h"

Settings::Settings(Gtk::Dialog::BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
    : Gtk::Dialog(cobject), builder(builder), settings(nullptr), switchButton(nullptr) {
    builder->get_widget("switchButton", switchButton);
    if (!switchButton) {
        throw std::runtime_error("No \'switchButton\' object in settings.glade");
    }

    settings = Gio::Settings::create("app-settings");
    settings->bind("switchButton", switchButton->property_active());
}

Settings *Settings::create(Gtk::Window &parent) {
    auto builder = Gtk::Builder::create_from_resource("/settings/settings.glade");

    Settings *dialog = nullptr;
    builder->get_widget_derived("settingsDialog", dialog);
    if (!dialog)
        throw std::runtime_error("No \"settingsDialog\" object in settings.glade");

    dialog->set_transient_for(parent);

    return dialog;
}
