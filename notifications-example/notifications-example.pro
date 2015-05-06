TARGET = notifications-example

QT += dbus

CONFIG += link_pkgconfig sailfishapp
PKGCONFIG += mlite5

SOURCES += src/notifications-example.cpp \
    src/notificationhelper.cpp \
    src/dbushelper.cpp

OTHER_FILES += qml/notifications-example.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/notifications-example.spec \
    notifications-example.desktop

HEADERS += \
    src/notificationhelper.h \
    src/dbushelper.h


