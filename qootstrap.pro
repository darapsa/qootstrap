TEMPLATE = lib
CONFIG += plugin qmltypes
QT += qml

QML_IMPORT_NAME = Bootstrap
QML_IMPORT_MAJOR_VERSION = 5
QML_IMPORT_MINOR_VERSION = 3

import.files = \
	qmldir \
	$${QML_IMPORT_NAME}.qml
import.path = $$[QT_INSTALL_QML]/$$QML_IMPORT_NAME

style.files = \
	ApplicationWindow.qml
style.path = $$[QT_INSTALL_QML]/QtQuick/Controls.2/$$QML_IMPORT_NAME

HEADERS += $${QML_IMPORT_NAME}.hxx
SOURCES += \
	$${QML_IMPORT_NAME}.cxx \
	tomlc99/toml.c
target.path = $$[QT_INSTALL_QML]/$$QML_IMPORT_NAME

INSTALLS += import style target