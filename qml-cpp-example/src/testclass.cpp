#include "testclass.h"

#include <QDebug>

TestClass::TestClass(QObject *parent) :
    QObject(parent)
{
}

void TestClass::testFunction()
{
    qDebug() << "executed";

    Q_EMIT testSignal();
}

QString TestClass::testString()
{
    return "Hello Sailors!";
}
