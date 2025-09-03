
#include "third.h"

Third::Third(QWidget* p, QHBoxLayout* l)
{
    parent=p;
    layout=l;
    m_Sobj=new QLabel(parent);
    m_Sobj->setText("Second label");
    layout->addWidget(m_Sobj);
    m_style();
}

void Third::slot(int count)
{
    m_Sobj->setText(QString::number(count));
}

void Third::m_style()
{
    m_Sobj->setFixedSize(200,100);
    m_Sobj->setStyleSheet(
        "background-color:lightblue;"
        "color:white;"
        "font:bold courier;"
        );
    m_Sobj->setAlignment(Qt::AlignCenter);
}
