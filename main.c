#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI
#endif

int getDays() {
    time_t timer;
    struct tm y2k = {0};
    double day;

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 122;
    y2k.tm_mon = 5;
    y2k.tm_mday = 1;

    time_t year = 122;
    printf("year:");
    scanf("%lld", (long long *) &year);
    y2k.tm_year = year - 1900;

    time_t mon = 5;
    printf("mon:");
    scanf("%lld", (long long *) &mon);
    y2k.tm_mon = mon - 1;

    time_t mday = 1;
    printf("mday:");
    scanf("%lld", (long long *) &mday);
    y2k.tm_mday = mday;

    time(&timer);  /* get current time; same as: timer = time(NULL) */
    int seconds = difftime(timer,mktime(&y2k));
    int days = seconds/60/60/24;

    return days;
}

char* getSignBioritm(int value) {
    return value > 0 ? "+" : "-";
}

int main ()
{
    setlocale(LC_ALL, "Russian");

    const int PERIOD_PHYSICAL_DAY = 23;
    const int PERIOD_EMOTIONAL_DAY = 28;
    const int PERIOD_INTELLECTUAL_DAY = 33;

    int days = getDays();

    int actualFhysicalBioritm = sin(2.0 * M_PI * days / PERIOD_PHYSICAL_DAY) * 100;
    int actualEmotionalBioritm = sin(2.0 * M_PI * days / PERIOD_EMOTIONAL_DAY) * 100;
    int actualIntellectualBioritm = sin(2.0 * M_PI * days / PERIOD_INTELLECTUAL_DAY) * 100;

    /*DEV*/
    printf("\nКоэффициенты: \nФизический %d\n",actualFhysicalBioritm);
    printf("Эмоциональный %d\n",actualEmotionalBioritm);
    printf("Ителектуальный %d\n",actualIntellectualBioritm);
    /*DEV*/

    char* signFhysicalBioritm = getSignBioritm(actualFhysicalBioritm);
    char* signEmotionalBioritm = getSignBioritm(actualEmotionalBioritm);
    char* signIntellectualBioritm = getSignBioritm(actualIntellectualBioritm);

    char result[120];
    sprintf(
        result, "%s%s\n%s%s\n%s%s\n",
        "Физический: ", signFhysicalBioritm,
        "Эмоциональный: ", signEmotionalBioritm,
        "Интеллектуальный: ", signIntellectualBioritm
    );

    printf("\nResult:\n%s", result);

    return 0;
}


