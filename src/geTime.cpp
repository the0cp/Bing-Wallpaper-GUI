#include "include/proc.h"

char *geTime()
{
    static char datetime[200];
    time_t now;
    struct tm *tm_now;

    time(&now);
    tm_now = localtime(&now);
    strftime(datetime, 200, "%m-%d-%Y", tm_now);

    return datetime;
}
