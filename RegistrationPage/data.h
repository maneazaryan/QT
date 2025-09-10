#ifndef DATA_H
#define DATA_H
#include <QMap>

class Data
{
private:
    static Data* m_data;
    QMap<QString,QString> m_map=
    {
        {"anna.a","Anna123$"},
        {"alice","Alice123$"},
        {"EveA","Eve123$"},
        {"an1111","An1234$"},
    };
    Data() ;
    ~Data();
public:
    static Data* GetInstance();
    bool Find_user(const QString& login,const QString& password);
    bool Add_user(const QString& login, const QString& password);
};

#endif // DATA_H
