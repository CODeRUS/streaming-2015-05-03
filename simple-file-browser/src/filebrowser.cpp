#include "filebrowser.h"

#include <QDir>
#include <QDirIterator>
#include <QFileInfoList>
#include <QFileInfo>

Filebrowser::Filebrowser(QObject *parent) :
    QAbstractListModel(parent)
{
    QStringList roles;
    roles.append("name");
    roles.append("path");
    roles.append("filepath");
    roles.append("size");
    roles.append("isDir");
    roles.append("isRoot");

    int roleIndex = Qt::UserRole + 1;
    foreach (const QString &role, roles) {
        _roles.insert(roleIndex, role.toUtf8());
        roleIndex++;
    }

    processPath(QDir::homePath());
}

int Filebrowser::rowCount(const QModelIndex &parent) const
{
    return _modelData.size();
}

QVariant Filebrowser::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (row < 0 || row >= _modelData.size())
        return QVariant();
    return _modelData[index.row()][_roles[role]];
}

void Filebrowser::processPath(const QString &path)
{
    _path = path;
    Q_EMIT pathChanged();

    QDir dir(path);
    QDirIterator dirIter(dir);

    beginResetModel();
    _modelData.clear();

    while (dirIter.hasNext()) {
        dirIter.next();

        QFileInfo info = dirIter.fileInfo();

        QVariantMap file;
        file["name"] = info.fileName();
        file["path"] = info.path();
        file["filepath"] = info.filePath();
        file["size"] = QFile(info.filePath()).size();
        file["isDir"] = info.isDir();
        file["isRoot"] = info.isRoot();

        _modelData.append(file);
    }

    endResetModel();
}

QString Filebrowser::getPath()
{
    return _path;
}
