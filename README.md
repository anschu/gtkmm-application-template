# Gtkmm-Application-Template

Simple template to write Gtkmm applications using CMake and Glade

## Requirements
* Gtkmm-3.0
* CMake-3.2
* Glade (optional)

## Getting started
1. Clone the repository with your preferred project-name:
```bash
git clone https://github.com/anschu/gtkmm-application-template.git $PROJECT_NAME$
cd $PROJECT_NAME$/
```
2. Change the default project-name `project(`**GtkmmApplicationTemplate**` VERSION 1.0)`  and application-ID `set(APPLICATION_ID "`**de.anschu**`.${PROJECT_NAME}")`in `CMakeLists.txt` located in the project root.

3. Write your code.

4. Build the project:
```bash
mkdir build
cd build/
cmake ..
```
5. Installation:
```bash
sudo make install
```

6. If you want to uninstall your application run the shellscript in the build-directory:
```bash
sudo ./uninstall.sh
```
