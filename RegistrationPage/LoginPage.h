#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include "RegistrationPage.h"
#include "data.h"
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QMessageBox>

class LoginPage : public QWidget
{
    QWidget*  m_parent;
    QDialog*  m_loginDialog;
    QLabel* m_logo ;
    QLineEdit* m_userName;
    QLineEdit* m_passWord;
    QPushButton* m_submit;
    QPushButton* m_reg;
    QString m_userloginText;
    QString m_userpasswordText;
public:
    LoginPage(QWidget* parent=nullptr);
    ~LoginPage();
private:
    void init_l_page();
    void makeRegPage();
    void find_user_page();
    void style();
private slots:
};

#endif // LOGINPAGE_H
