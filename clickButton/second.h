#ifndef SECOND_H
#define SECOND_H
#include <QObject>

class Second : public QObject
{
    Q_OBJECT
    int count=0;
public:
    Second(QObject* parent=nullptr) : QObject(parent) {}
public slots:
    void slot();

signals:
    void sendsignal(int count);
};

#endif // SECOND_H
