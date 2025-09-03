#include "number.h"


double Number:: GetNumber()
{
    double a =  m_number;
    ChangeNum();
    return a;
}
double Number::initNumber(double n)
{
    if( m_number == 0 && n==0)
        return m_number;
    else
        m_number=m_number*10+n;
    return m_number;
}
double Number:: GetNum()
{
    return m_number;
}
void Number::ChangeNum()
{
    m_number=0;
}
