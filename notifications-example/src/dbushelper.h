#ifndef DBUSHELPER_H
#define DBUSHELPER_H

#include <QObject>

class DBusHelper : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.test.dbus")
public:
    explicit DBusHelper(QObject *parent = 0);

signals:
    void notificationClicked(const QString &notificationName);

public slots:
    Q_SCRIPTABLE void notificationCallback(const QString &notificationName);

};

#endif // DBUSHELPER_H
