#include "mainwindow.h"
#include "LoginPage.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsOpacityEffect>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWidget* central = new QWidget(&w);
    w.setCentralWidget(central);
    central -> setStyleSheet("border-image: url(:/img/bb.jpg) 0 0 0 0 stretch stretch;");
    QPushButton* button = new QPushButton("Login",central);
    button -> setFixedSize(160,40);
    button -> setStyleSheet(
        "border:1px solid white;"
        "border-image:none;"
        "border-radius:5px;"
        "background:#F291CF;"
        );
    QGraphicsOpacityEffect* op = new QGraphicsOpacityEffect(button);
    op -> setOpacity(0.7);
    button -> setGraphicsEffect(op);
    QVBoxLayout* layout = new QVBoxLayout(central);
    layout -> addWidget(button,0,Qt::AlignCenter);

    QObject::connect(button,&QPushButton::clicked, [&w, button](){
       // button -> hide();
        LoginPage* login = new LoginPage(&w);
    } );

    w.show();
    return a.exec();
}
