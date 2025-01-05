#include <stdio.h>

int main() {
    long number1 = 0;
    long number2 = 0;
    long *pnumber = NULL;

    pnumber = &number1;
    *pnumber = 2;
    ++number2;
    number2 += *pnumber;

    pnumber = &number2;
    ++*pnumber;

    printf(
        "number1 = %ld, number2 = %ld, *pnumber = %ld, *pnumber + number2 = "
        "%ld\n",
        number1, number2, *pnumber, *pnumber + number2);

    return 0;
}
