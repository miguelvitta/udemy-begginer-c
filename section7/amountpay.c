#include <stdio.h>
#include <stdbool.h>

#define PAYRATE 12.0
#define TAXRATE_300 0.15
#define TAXRATE_450 0.2
#define TAXRATE_REST 0.25
#define OVERTIME 40.0

int main()
{
    double hoursWorked = 0.0;
    double regularHours = 0.0;
    double overtimeHours = 0.0;
    double grossPay = 0.0;
    double taxAmount = 0.0;
    bool validInput = false;

    while(!validInput) {
        printf("Enter the amount of hours you work in a week: ");
        if(scanf("%lf", &hoursWorked) != 1 || hoursWorked <= 0) {
            printf("Invalid input. Please enter a positive number.\n");
            while (getchar() != '\n');
        } else {
            validInput = true;
        }
    }

    if(hoursWorked <= OVERTIME) {
        regularHours = hoursWorked;
        grossPay = regularHours * PAYRATE;
    }
    else {
        regularHours = OVERTIME;
        overtimeHours = hoursWorked - OVERTIME;       
        grossPay = (regularHours * PAYRATE) + (overtimeHours * 1.5 * PAYRATE);
    }
    
    if(grossPay > 450.0) {
        taxAmount = (300.0 * TAXRATE_300) + (150.0 * TAXRATE_450) + ((grossPay - 450) * TAXRATE_REST);
    }
    else {
        if(grossPay > 300.0) {
            taxAmount = (300.0 * TAXRATE_300) + ((grossPay - 300) * TAXRATE_450);
        }
        else {
            taxAmount = grossPay * TAXRATE_300;
        }
    }
    printf("You worked %.2lf hours, including %.2lf overtime hours.\n", hoursWorked, overtimeHours);
    printf("Gross pay: $%.2lf\n", grossPay);
    printf("Taxes: $%.2lf\n", taxAmount);
    printf("Net pay: $%.2lf\n", grossPay - taxAmount);

    return 0;
}
