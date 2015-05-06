#include "dbushelper.h"
#include <QDBusConnection>

#include <QDebug>

DBusHelper::DBusHelper(QObject *parent) :
    QObject(parent)
{
    QDBusConnection::sessionBus().registerService("org.test.dbus");
    QDBusConnection::sessionBus().registerObject("/", this, QDBusConnection::ExportScriptableSlots);
}

void DBusHelper::notificationCallback(const QString &notificationName)
{
    qDebug() << "executed";

    Q_EMIT notificationClicked(notificationName);
}
