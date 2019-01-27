# Gtkmm-Application-Template

Simple template to write Gtkmm applications using CMake and Glade

## Requirements
* Gtkmm-3.0
* CMake-3.2 or higher
* Glade (optional)

## Getting started
1. Clone repository with preferred project name:
```bash
git clone https://github.com/anschu/gtkmm-application-template.git PROJECT_NAME
```

2. Run initialization script located in the project root...
```bash
cd PROJECT_NAME/
bash init.sh
```
...and choose your application-ID e.g. "org.gtkmm.MyApplication".

3. Write your code.

4. Build the project:
```bash
mkdir build
cd build/
cmake ..
make
```
5. Installation:
```bash
sudo make install
```

6. If you want to uninstall your application run the shellscript in the build-directory:
```bash
sudo ./uninstall.sh
```

## References
Most parts used in the source code are copied from the GNOME Developer Guide [Programming with gtkmm3](https://developer.gnome.org/gtkmm-tutorial/stable/ "Programming with gtkmm3"), especially chapter [Building applications](https://developer.gnome.org/gtkmm-tutorial/stable/chapter-building-applications.html.en "Building applications").
