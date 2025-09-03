
#ifndef THIRD_H
#define THIRD_H
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QObject>

class Third : public QObject
{
    Q_OBJECT
    QLabel* m_Sobj;
    QWidget* parent;
    QHBoxLayout* layout;
public:
    Third(QWidget* p=nullptr, QHBoxLayout* l=nullptr );
public slots:
    void slot(int count);
private:
    void m_style();
};
#endif // THIRD_H
