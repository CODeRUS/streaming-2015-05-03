#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QAbstractListModel>

class Filebrowser : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Filebrowser(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QHash<int, QByteArray> roleNames() const { return _roles; }

    Q_PROPERTY(QString path READ getPath WRITE processPath NOTIFY pathChanged)
    QString _path;
    QString getPath();
    void processPath(const QString &path);

private:
    QHash<int, QByteArray> _roles;
    QVector<QVariantMap> _modelData;

signals:
    void pathChanged();

public slots:

};

#endif // FILEBROWSER_H
