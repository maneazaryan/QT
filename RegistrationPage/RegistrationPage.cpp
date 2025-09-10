#include "RegistrationPage.h"

RegistrationPage::RegistrationPage(QWidget* parent) :m_parent(parent)
{
    init_rPage();
}
RegistrationPage::~RegistrationPage(){}

void RegistrationPage::init_rPage()
{
    //Dialog
    m_RegDialog = new QDialog(m_parent);
    m_RegDialog -> setWindowTitle("Registration");
    m_RegDialog -> resize(400,400);
    //logo
    m_logo = new QLabel(m_RegDialog);
    m_logo->setFixedSize(100,100);
    QPixmap pix(":/img/logo.png");
    m_logo->setPixmap(pix.scaled(m_logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //userName
    m_userName = new QLineEdit(m_RegDialog);
    m_userName -> setPlaceholderText("Username...");
    //username validator
    QRegularExpression re ("^(?=.{3,20}$)(?![._])(?!.*[._]{2})[A-Za-z0-9._]+(?<![._])$");
    QRegularExpressionValidator* val= new QRegularExpressionValidator(re,m_userName );
    m_userName -> setValidator(val);
    m_userName -> setToolTip("Username must be 3-20 chars, no consecutive ․ or ―.");
    m_userName -> setToolTipDuration(20000);
    QObject::connect(m_userName, &QLineEdit::textChanged, this, &RegistrationPage::validate_login);

    //Password
    m_password = new QLineEdit(m_RegDialog);
    m_password -> setPlaceholderText("Password...");
    m_password -> setEchoMode(QLineEdit::Password);
    //password validator
    QRegularExpression rePWord ("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{6,30}$");
    QRegularExpressionValidator* valPWord = new QRegularExpressionValidator (rePWord, m_password);
    m_password -> setValidator(valPWord);
    m_password -> setToolTip("Password must be 6-30 characters long,\n"
                           "include at least one uppercase letter,\n"
                           "one lowercase letter, one number,\n"
                           "and one special character (@$!%*?&).");
    m_password -> setToolTipDuration(20000);

    QObject::connect(m_password, &QLineEdit::textChanged, this,&RegistrationPage::validate_pWord);

    //save
    m_save = new QPushButton("Save",m_RegDialog);
    m_save -> setEnabled(false);
    QObject::connect(m_save, &QPushButton::clicked, this, &RegistrationPage::addData);

    //widget
    QWidget* wid = new QWidget(m_RegDialog);
    wid -> resize(200, 200);
    //layout
    QVBoxLayout* regLayout = new QVBoxLayout(m_RegDialog);
    regLayout -> addStretch();
    regLayout -> addWidget(m_logo,0,Qt::AlignCenter);
    regLayout -> addWidget(wid,0,Qt::AlignCenter);
    regLayout -> addStretch();

    QVBoxLayout* widLayout = new QVBoxLayout(wid);
    widLayout -> addWidget(m_userName,0,Qt::AlignCenter);
    widLayout -> addWidget(m_password,0,Qt::AlignCenter);
    widLayout -> addWidget(m_save,0,Qt::AlignCenter);

    style();
    m_RegDialog->exec();
}

void RegistrationPage::validate_login()
{
    if(!m_userName -> hasAcceptableInput())
    {
        m_userName -> setStyleSheet("border:2px solid red");
    }
    else
    {
        m_userName -> setStyleSheet("border:2px solid lightgreen");
        m_isLoginValid = true;
    }
}
void RegistrationPage::validate_pWord()
{
    if(!m_password -> hasAcceptableInput())
    {
        m_password -> setStyleSheet("border:2px solid red");
    }
    else
    {
        m_password -> setStyleSheet("border:2px solid lightgreen");
        m_isPassWordValid = true;
    }
    updateSaveButtonState();
}
void RegistrationPage::updateSaveButtonState()
{
    if(m_isLoginValid && m_isPassWordValid)
    {
        m_save -> setEnabled(true);
    }
}
void RegistrationPage::addData()
{
    QString newLogin = m_userName -> text();
    QString newPword = m_password -> text();
    Data* data = Data::GetInstance();
    if(data->Add_user(newLogin, newPword))
    {
        QMessageBox::information(this,"Registration", "User successfully registered!");
        m_RegDialog->close();
    }
    else
    {
        QMessageBox::warning(this, "Registration", "Username already exists!");
    }
}
void RegistrationPage::style()
{
    m_userName -> setFixedSize(160,35);
    m_password -> setFixedSize(160,35);
    m_save -> setFixedSize(160,35);
    m_save -> setStyleSheet(
        "QPushButton {"
        "   border: 1px solid #FFFFFF;"
        "   border-radius: 8px;"
        "   padding: 6px;"
        "   color: #FFFFFF;"
        "   background-color: none;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover{"
        "color:#FFFFFF;"
        "background-color:#E9C2F0"
        "}"
        "QPushButton:pressed {"
        "   background-color: #FFFFFF;"
        "}"
        );
}
