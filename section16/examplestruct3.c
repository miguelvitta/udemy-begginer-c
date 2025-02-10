#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main() {
    struct date today, *datePtr;

    datePtr = &today;

    datePtr->month = 2;
    datePtr->day = 10;
    datePtr->year = 2025;

    printf("Today's date is %i/%i/%.2i.\n", datePtr->month, datePtr->day,
           datePtr->year);

    return 0;
}

