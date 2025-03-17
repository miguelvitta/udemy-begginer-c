#include <stdio.h>
#include <stdlib.h>

struct date {
    int month;
    int day;
    int year;
};

int main() {
    struct date* datePtr;

    datePtr = malloc(sizeof(struct date));
    if (datePtr == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    datePtr->month = 3;
    datePtr->day = 17;
    datePtr->year = 2025;

    printf("Today's date is %i/%i/%02i\n", datePtr->month, datePtr->day, datePtr->year % 100);

    free(datePtr);

    return 0;
}
