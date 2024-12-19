#include <stdio.h>

int main()
{
    int total = 0, years = 0, months = 0, days = 0, hours = 0, minutes = 0, remainder = 0;
    long double minutesInYear = 365.0 * 24.0 * 60.0;
    long double yearsR = 0.0, daysR = 0.0;

    printf("Enter the total number of minutes: ");
    scanf("%d", &total);

    years = total / (int)minutesInYear;
    remainder = total % (int)minutesInYear;
    months = remainder / (30 * 24 * 60);
    remainder %= (30 * 24 * 60);
    days = remainder / (24 * 60);
    remainder %= (24 * 60);
    hours = remainder / 60;
    minutes = remainder % 60;

    int totalMinutes = total;
    yearsR = totalMinutes / minutesInYear;
    daysR = totalMinutes / (24.0 * 60.0);

    printf("The total time, in absolute terms, is equivalent to %d years, %d months, %d days, %d hours, and %d minutes\n", 
           years, months, days, hours, minutes);
    printf("The total time, in relative terms, is equivalent to %Lf years, and also equal to %Lf days\n", 
           yearsR, daysR);

    return 0;
}
