#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H
#include "data.h"
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>
class RegistrationPage: public QWidget
{
private:
    QWidget* m_parent;
    QDialog* m_RegDialog;
    QLabel* m_logo;
    QLineEdit* m_userName;
    QLineEdit* m_password;
    QPushButton* m_save;
    bool m_isLoginValid = false;
    bool m_isPassWordValid = false;
public:
    RegistrationPage(QWidget* parent = nullptr);
    ~RegistrationPage();
private:
    void init_rPage();
    void updateSaveButtonState();
    void style();
private slots:
    void validate_login();
    void validate_pWord();
    void addData();
};

#endif // REGISTRATIONPAGE_H
