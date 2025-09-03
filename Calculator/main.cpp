#include "mainwindow.h"
#include "calculate.h"
#include "number.h"
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QString>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QWidget* center = new QWidget(&w);
    w.setCentralWidget(center);

    QWidget* h1 = new QWidget(center);
    QWidget* h2 = new QWidget(center);

    h1->setFixedSize(400,400);
    h1->setStyleSheet("background-color:grey;");

    h2->setFixedSize(130,400);
    h2->setStyleSheet("background-color:grey;");


    QWidget* nums= new QWidget(h1);
    nums->setFixedSize(300,300);

    QPushButton* n1= new QPushButton("1",nums);
    QPushButton* n2= new QPushButton("2",nums);
    QPushButton* n3= new QPushButton("3",nums);
    QPushButton* n4= new QPushButton("4",nums);
    QPushButton* n5= new QPushButton("5",nums);
    QPushButton* n6= new QPushButton("6",nums);
    QPushButton* n7= new QPushButton("7",nums);
    QPushButton* n8= new QPushButton("8",nums);
    QPushButton* n9= new QPushButton("9",nums);
    QPushButton* n0= new QPushButton("0",nums);

    QLabel* currentNumber = new QLabel(h1);
    QPushButton* b_e= new QPushButton("=",h1);
    QLabel* result = new QLabel(h1);
    result->setText("-");
    result->setAlignment(Qt::AlignCenter);
    result->setFixedSize(100,50);
    result->setStyleSheet("background-color:orange;");

    currentNumber->setAlignment(Qt::AlignCenter);
    currentNumber->setFixedSize(100,30);
    currentNumber->setStyleSheet("border:solid 2px white;"
                                 "background-color:lightyellow;");


    QPushButton* b_a= new QPushButton("+",h2);
    QPushButton* b_s= new QPushButton("-",h2);
    QPushButton* b_m= new QPushButton("*",h2);
    QPushButton* b_d= new QPushButton("/",h2);

    QHBoxLayout* lh = new QHBoxLayout(center);
    lh->addStretch();
    lh->addWidget(h1);
    lh->addWidget(h2);
    lh->addStretch();

    QVBoxLayout* l_vl = new QVBoxLayout(h1);
    l_vl->addWidget(nums);
    l_vl->addWidget(currentNumber);
    l_vl->addWidget(b_e);
    l_vl->addWidget(result);
    l_vl->setAlignment(nums,Qt::AlignHCenter);
    l_vl->setAlignment(currentNumber,Qt::AlignHCenter);
    l_vl->setAlignment(result,Qt::AlignHCenter);

    QGridLayout* l_g= new QGridLayout(nums);
    l_g->addWidget(n1,0,0,1,1);
    l_g->addWidget(n2,0,1,1,1);
    l_g->addWidget(n3,0,2,1,1);
    l_g->addWidget(n4,1,0,1,1);
    l_g->addWidget(n5,1,1,1,1);
    l_g->addWidget(n6,1,2,1,1);
    l_g->addWidget(n7,2,0,1,1);
    l_g->addWidget(n8,2,1,1,1);
    l_g->addWidget(n9,2,2,1,1);
    l_g->addWidget(n0,3,1,1,1);

    QVBoxLayout* l_vr = new QVBoxLayout(h2);
    l_vr->addWidget(b_a);
    l_vr->addWidget(b_s);
    l_vr->addWidget(b_m);
    l_vr->addWidget(b_d);

    double first= 0;
    double second= 0;
    double n=0;

    QString op;
    Calculate* c= new Calculate;
    Number* number= new Number;

    QObject::connect(n1,&QPushButton::clicked,[&n,number,currentNumber]()
                     {
                        n=1;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                    });
    QObject::connect(n2,&QPushButton::clicked,[&n,number,currentNumber]()
                     {
                        n=2;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                    });
    QObject::connect(n3,&QPushButton::clicked,[&n,number,currentNumber]()
                    {
                        n=3;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                     });
    QObject::connect(n4,&QPushButton::clicked,[&n,number,currentNumber]()
                    {
                        n=4;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                    });
    QObject::connect(n5,&QPushButton::clicked,[&n, number,currentNumber]()
                    {
                        n=5;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                    });
    QObject::connect(n6,&QPushButton::clicked,[&n, number,currentNumber]()
                    {
                        n=6;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                        });
    QObject::connect(n7,&QPushButton::clicked,[&n, number,currentNumber]()
                    {
                        n=7;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                    });
    QObject::connect(n8,&QPushButton::clicked,[&n, number,currentNumber]()
                    {
                        n=8;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                    });
    QObject::connect(n9,&QPushButton::clicked,[&n, number,currentNumber]()
                    {
                        n=9;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                        });
    QObject::connect(n0,&QPushButton::clicked,[&n, number,currentNumber]()
                    {
                        n=0;
                        number->initNumber(n) ;
                        double r = number->GetNum();
                        currentNumber->setText(QString::number(r));
                    });

    QObject::connect(b_a,&QPushButton::clicked,[&op, &first, number]()
                    {
                        op="+";
                        first=number->GetNumber();
                        number->ChangeNum();
                    });
    QObject::connect(b_s,&QPushButton::clicked,[&op, &first, number]()
                    {
                        op="-";
                        first=number->GetNumber();
                        number->ChangeNum();
                        });
    QObject::connect(b_m,&QPushButton::clicked,[&op, &first, number]()
                    {
                        op="*";
                        first=number->GetNumber();
                        number->ChangeNum();
                    });
    QObject::connect(b_d,&QPushButton::clicked,[&op, &first, number]()
                    {
                        op="/";
                        first=number->GetNumber();
                        number->ChangeNum();
                        });
    QObject::connect(b_e,&QPushButton::clicked,[result,c,&first,&second,&op,number]()
                    {
                        second=number->GetNumber();
                        double r= c->GetResult(first,second,op);
                        result->setText(QString::number(r));
                    });

    w.showMaximized();
    return a.exec();
}
