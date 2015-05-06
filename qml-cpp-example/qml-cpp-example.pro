# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = qml-cpp-example

CONFIG += sailfishapp

SOURCES += src/qml-cpp-example.cpp \
    src/testclass.cpp

OTHER_FILES += qml/qml-cpp-example.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/qml-cpp-example.changes.in \
    rpm/qml-cpp-example.spec \
    rpm/qml-cpp-example.yaml \
    translations/*.ts \
    qml-cpp-example.desktop

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/qml-cpp-example-de.ts

HEADERS += \
    src/testclass.h

