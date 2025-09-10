#include "data.h"

Data::Data(){}

Data::~Data()
{}
Data* Data::GetInstance()
{
    if(m_data==nullptr)
    {
        m_data = new Data();
    }
    return m_data;
}
bool Data::Find_user(const QString& login, const QString& password)
{
    auto it = m_map.find(login);
    if(it != m_map.end() && it.value() == password)
        return true;
    else return false;
}
bool Data::Add_user(const QString& login, const QString& password)
{
    if(m_map.contains(login))
    {
        return false;
    }
    else
    {
        m_map.insert(login,password);
        return true;
    }
}
Data* Data::m_data = nullptr;
