# Gtkmm-Application-Template

Simple template to write Gtkmm applications using CMake and Glade

## Requirements
* Gtkmm-3.0
* CMake-3.2
* Glade (optional)

## Getting started
1. Clone repository with preferred project name:
`git clone git@github.com:anschu/gtkmm-application-template.git PROJECT_NAME`

2. Run initialization script located in the project root...
```bash
cd PROJECT_NAME/
sh init.sh
```
...and choose your application-ID e.g. "org.gtkmm.MyApplication".

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
