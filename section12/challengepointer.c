#include <stdio.h>

int main() {
    int n = 10;
    int *pn = NULL;

    pn = &n;

    printf("Adress of n: %p\n", &n);
    printf("Value of n: %d\n", n);

    printf("Adress of pn: %p\n", &pn);
    printf("Value of pn: %p\n", pn);
    printf("Value that pn is pointing to: %d\n", *pn);

    return 0;
}
