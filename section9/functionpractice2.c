#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int multiplyTwoNumbers(long long int a, long long int b);

int main() {
    srand((time(NULL)));
    for(int i = 0; i < 20; i++) {
        long long int x = rand() % 10000;
        long long int y = rand() % 10000;
        long long int result = 0;

        result = multiplyTwoNumbers(x, y);

        printf("The product of %lld multiplied by %lld is: %lld\n", x, y, result);
    }
}

long long int multiplyTwoNumbers(long long int b, long long int a) {
    long long int result = a * b;
    return result;
}
