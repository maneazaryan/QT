#include "calculate.h"

double Calculate::m_add(double x, double y)
{
    return x+y;
}
double Calculate::m_sub(double x, double y)
{
    return x-y;
}
double Calculate::m_mult(double x, double y)
{
    return x*y;
}
double Calculate::m_div(double x, double y)
{
    if(y!=0)
        return x/y;
    else 0;
}
double Calculate::GetResult(double x, double y, QString& op )
{
    double res=0;
    if(op=="+") res=m_add(x,y);
    if(op=="-") res= m_sub(x,y);
    if(op=="*") res= m_mult(x,y);
    if(op=="/") res=m_div(x,y);
    return res;
}
