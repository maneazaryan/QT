#include "LoginPage.h"

LoginPage::LoginPage(QWidget* parent): m_parent(parent)
{
    init_l_page();

}
LoginPage::~LoginPage(){};

void LoginPage::init_l_page()
{
    m_loginDialog = new QDialog(m_parent);
    m_loginDialog -> setWindowTitle("USER LOGIN");
    //logo
    m_logo = new QLabel(m_loginDialog);
    m_logo->setFixedSize(100,100);
    QPixmap pix(":/img/logo.png");
    m_logo->setPixmap(pix.scaled(m_logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //username
    m_userName = new QLineEdit(m_loginDialog );
    m_userName -> setPlaceholderText("Username...");
    m_userName -> setMaxLength(20);
    //password
    m_passWord = new QLineEdit(m_loginDialog);
    m_passWord ->setPlaceholderText("Password...");
    m_passWord -> setEchoMode(QLineEdit::Password);
    m_passWord -> setMaxLength(100);
    //submit
    m_submit = new QPushButton("Login",m_loginDialog);
    QObject::connect(m_submit, &QPushButton::clicked, this , &LoginPage::find_user_page);
    m_reg = new QPushButton("Registration",m_loginDialog);
    QObject::connect(m_reg, &QPushButton::clicked,this,&LoginPage::makeRegPage);
    //layout
    QVBoxLayout* log_layout = new QVBoxLayout(m_loginDialog );
    log_layout -> addWidget(m_logo, 0,  Qt::AlignHCenter);
    log_layout -> addWidget(m_userName, 0,  Qt::AlignHCenter);
    log_layout -> addWidget(m_passWord, 0,  Qt::AlignHCenter);
    log_layout -> addWidget(m_submit, 0,  Qt::AlignHCenter);
    log_layout -> addWidget(m_reg, 0,  Qt::AlignHCenter);
    style();
    m_loginDialog->exec();
}
void LoginPage::find_user_page()
{
    m_userloginText = m_userName->text();
    m_userpasswordText = m_passWord->text();
    Data* data = Data::GetInstance();
    if(data->Find_user(m_userloginText,m_userpasswordText))
    {
        m_loginDialog->close();
    }
    else
    {
        QMessageBox::information(this,"Login Failed","Invalid username or password");
    }
}
void LoginPage::makeRegPage()
{
    //RegistrationPage* regPage = new RegistrationPage(m_Parent);
    RegistrationPage regPage (m_loginDialog);
    m_loginDialog->close();
}
void LoginPage::style()
{
    //dialog
    m_loginDialog -> resize(400,400);
    m_userName -> setFixedSize(160,35);
    m_passWord -> setFixedSize(160,35);
    m_submit -> setFixedSize(160,35);
    m_loginDialog -> setStyleSheet(
        "QDialog {"
        "   border-radius: 15px;"
        "   background-color: #E9C2F0;"
        "}"
        "QLineEdit{"
        "   border: none;"
        "   border-radius: 8px;"
        "   padding: 6px;"
        "}"
        "QPushButton {"
        "   border-radius: 8px;"
        "   padding: 6px;"
        "   background-color:white;"
        "   color: #E9C2F0;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover{"
        "   background-color:#E9C2F0;"
        "   color:white ;"
        "}"
        );
    m_reg -> setStyleSheet(" background-color: none;color:white");

}
