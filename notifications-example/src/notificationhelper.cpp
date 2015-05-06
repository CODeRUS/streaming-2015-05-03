#include "notificationhelper.h"

#include "mlite5/MNotification"
#include "mlite5/MRemoteAction"

NotificationHelper::NotificationHelper(QObject *parent) :
    QObject(parent)
{
}

void NotificationHelper::sendNotification(const QString &body, const QString &summary, const QString &name)
{
    MNotification notification;
    notification.setBody(body);
    notification.setSummary(summary);

    MRemoteAction action("org.test.dbus", "/", "org.test.dbus", "notificationCallback", QVariantList() << name);
    notification.setAction(action);

    notification.publish();
}
