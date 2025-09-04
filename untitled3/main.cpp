#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QObject>
#include <QString>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWidget* centralWidget= new QWidget(&w);
    w.setCentralWidget(centralWidget);

    w.setStyleSheet(
        "QPushButton{background-color:#bdcebe;font:bold 20px Courier; "
                "color:white;border:none; border-radius:9px }"
        "QPushButton:hover{background-color:white;font:bold 20px Courier; "
                "color:#bdcebe;border:none; border-radius:9px }"
        "QLineEdit{background-color:#bdcebe;font:bold 20px Courier;"
                " color:white;border:none; border-radius:9px}"
        );

    QLabel* lable1 = new QLabel(centralWidget);
    lable1->setFixedSize(338,100);
    lable1->setAlignment(Qt::AlignCenter);
    lable1->setStyleSheet("background-color:#bdcebe;font:bold 20px Courier; color:white;");

    QLabel* lable2 = new QLabel(centralWidget);
    lable2->setFixedSize(338,450);
    QPixmap pix(":/img/pexels-mane-azaryan-305108328-27740176.jpg");
    lable2->setPixmap(pix.scaled(lable2->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QVBoxLayout* vl= new QVBoxLayout(centralWidget);
    vl->addStretch();
    vl->addWidget(lable1,0,Qt::AlignCenter);
    vl->addWidget(lable2,0,Qt::AlignCenter);
    vl->addStretch();

    QDialog* dialog = new QDialog(&w);
    dialog->setWindowTitle("QT homework");
    dialog->setFixedSize(600,400);

    QLineEdit* lineEdit = new QLineEdit(dialog);
    lineEdit->setPlaceholderText("Enter a text");
    lineEdit->setFixedSize(200,60);

    QPushButton* pb = new QPushButton("Send the text", dialog);
    pb->setFixedSize(200,60);

    QObject::connect(pb,&QPushButton::clicked,[lineEdit, lable1, dialog](){
        QString inputtext = lineEdit->text();
        if(!inputtext.isEmpty())
        {
            lable1->setText(inputtext);
            dialog->close();
        }
    });

    QHBoxLayout* layout= new QHBoxLayout(dialog);
    layout->addWidget(lineEdit);
    layout->addWidget(pb);

    dialog->exec();
    w.show();
    return a.exec();
}
