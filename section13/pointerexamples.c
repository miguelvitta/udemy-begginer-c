#include <stdio.h>

int main() {
    int number = 0;
    int *pnumber = NULL;
    number = 10;
    pnumber = &number;
    *pnumber += 25;

    printf("Adress of number: %p\n", &number);
    printf("Value of number: %d\n", number);

    printf("Adress of pnumber: %p\n", &pnumber);
    printf("Value of pnumber: %p\n", pnumber);
    printf("Value that pnumber is pointing to: %d\n", *pnumber);
    return 0;
}
