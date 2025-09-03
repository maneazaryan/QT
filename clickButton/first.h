
#ifndef FIRST_H
#define FIRST_H
#include <QWidget>
#include <QPushButton>

#include <QHBoxLayout>
#include <QObject>

class First : public QObject
{
    Q_OBJECT
    QPushButton* m_Fobj;
    QWidget* parent;
    QHBoxLayout* layout;
public :
    First(QWidget* p=nullptr, QHBoxLayout* l=nullptr );

    QPushButton* getButton();
    void slot();
signals :
    void sendSignal();
private:
    void m_style();
};
#endif // FIRST_H
