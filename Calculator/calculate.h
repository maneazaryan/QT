#ifndef CALCULATE_H
#define CALCULATE_H
#include <QObject>
#include <QString>

class Calculate: public QObject
{
    Q_OBJECT
    double m_add(double x, double y);
    double m_sub(double x, double y);
    double m_mult(double x, double y);
    double m_div(double x, double y);
public:
    double GetResult(double x, double y, QString& op);
};

#endif // CALCULATE_H
