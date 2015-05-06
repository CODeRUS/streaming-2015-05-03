#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>

class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = 0);

    Q_INVOKABLE void testFunction();
    Q_INVOKABLE QString testString();

public slots:

signals:
    void testSignal();

};

#endif // TESTCLASS_H
