#include "second.h"


void Second::slot()
{
    count++;
    emit sendsignal(count);
}
