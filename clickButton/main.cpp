    #include "mainwindow.h"
    #include "first.h"
#include "second.h"
    #include "third.h"
    #include <QApplication>
    #include <QWidget>
    #include <QHBoxLayout>
    #include <QObject>

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.setWindowTitle("Signal/slot");
        QWidget* center = new QWidget(&w);
        w.setCentralWidget(center);
        center->setStyleSheet("background-color:skyblue");

        QHBoxLayout* layout = new QHBoxLayout();
        center->setLayout(layout);

        First* f1 = new First(center, layout);
        Second* s2 = new Second;
        Third* t3 = new Third(center, layout);
        QObject::connect(f1->getButton(),&QPushButton::clicked,f1,&First::slot);

        QObject::connect(f1,&First::sendSignal,s2,&Second::slot);

        QObject::connect(s2, &Second::sendsignal, t3, &Third::slot);

        w.showMaximized();
        return a.exec();
    }
