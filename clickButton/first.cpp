
#include "first.h"

First::First(QWidget* p, QHBoxLayout* l)
{
    parent=p;
    layout=l;
    m_Fobj=new QPushButton(parent);
    m_Fobj->setText("Click me");
    layout->addWidget(m_Fobj);
    m_style();
}
QPushButton* First::getButton()
{
    return m_Fobj ;
}
void First::slot()
{
    emit sendSignal();
}

void First::m_style()
{
    m_Fobj->setFixedSize(200,100);
    m_Fobj->setStyleSheet(
        "background-color:lightblue;"
        "color:white;"
        "border:none;"
        "font:bold courier;"
        );
}
