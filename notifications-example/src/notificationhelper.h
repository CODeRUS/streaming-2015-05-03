#ifndef NOTIFICATIONHELPER_H
#define NOTIFICATIONHELPER_H

#include <QObject>

class NotificationHelper : public QObject
{
    Q_OBJECT
public:
    explicit NotificationHelper(QObject *parent = 0);

    Q_INVOKABLE void sendNotification(const QString &body, const QString &summary, const QString &name);

signals:

public slots:

};

#endif // NOTIFICATIONHELPER_H
