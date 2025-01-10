#include <stdio.h>

void squareNumber(int * const n);

int main() {
    int x = 0;
    scanf("%d", &x);
    squareNumber(&x);
    printf("the square of the number is: %d\n", x);
    return 0;
}

void squareNumber(int * const n) {
    *n = (*n) * (*n);
}
