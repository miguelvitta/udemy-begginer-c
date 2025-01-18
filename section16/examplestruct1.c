#include <stdio.h>

int main() {
    struct date {
        int month;
        int day;
        int year;
    };

    struct date today;

    today.month = 1;
    today.day = 16;
    today.year = 2025;

    printf("Today's date is: %d/%d/%2d\n", today.month, today.day, today.year%100);    
    
    return 0;
}
