TEMPLATE = lib
CONFIG += qt plugin qmltypes
QT += qml

QML_IMPORT_NAME = Bootstrap
QML_IMPORT_MAJOR_VERSION = 5
QML_IMPORT_MINOR_VERSION = 3

DESTDIR = imports/$$QML_IMPORT_NAME
TARGET = qtquickcontrols2bootstrapstyleplugin

HEADERS += bootstrap.hxx
SOURCES += bootstrap.cxx
