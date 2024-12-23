#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyTwoNumbers(long long int x, long long int y);

int main() {
    srand((time(NULL)));
    for(int i = 0; i < 20; i++) {
        long long int x = rand();
        long long int y = rand();
        multiplyTwoNumbers(x, y);
    }
}

void multiplyTwoNumbers(long long int x, long long int y) {
    long long int result = x * y;
    printf("The product of %lld multiplied by %lld is: %lld\n", x, y, result);
}
