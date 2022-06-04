/* time example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int day(int y, int m, int d) {
    setlocale(LC_ALL, "Russian");
    return 367 * y - 7 * (y + (m + 9) / 12) / 4 + 275 * m / 9 + d - 730530;
}

int main ()
{

    time_t timer;
    struct tm y2k = {0};
    double seconds;

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 122;
    y2k.tm_mon = 5;
    y2k.tm_mday = 1

    time_t year = 122;
    printf("year:");
    scanf("%lld", (long long *) &year);
    printf("%lld\n", (long long) year);
    y2k.tm_year = year;

    time_t mon = 5;
    printf("mon:");
    scanf("%lld", (long long *) &mon);
    printf("%lld\n", (long long) mon);
    y2k.tm_mon = mon;

    time_t mday = 1;
    printf("mday:");
    scanf("%lld", (long long *) &mday);
    printf("%lld\n", (long long) mday);
    y2k.tm_mday = mday;




    time(&timer);  /* get current time; same as: timer = time(NULL)  */

    seconds = difftime(timer,mktime(&y2k));

    printf ("%.f seconds since January 1, 2000 in the current timezone", seconds/60/60/24);
    return 0;
}



