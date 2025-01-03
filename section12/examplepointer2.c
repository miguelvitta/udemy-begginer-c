#include <stdio.h>

int main() {
    int number = 0;
    int *pnumber = NULL;

    number = 10;
    printf("number's adress: %p.\n", &number);
    printf("number's value: %d.\n\n", number);

    pnumber = &number;

    printf("pnumber's adress: %p\n", (void*)&number);
    printf("pnumber's size: %zd.\n", sizeof(number));
    printf("pnumber's value: %p.\n", pnumber);
    printf("value pointed to: %d.\n", *pnumber);

    return 0;
}
