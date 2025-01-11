#include <stdio.h>

int arraySum(int array[], int n);

int main() {
    int n = 0;
    printf("Choose the size of the array: ");
    scanf("%d", &n);
    int array[n];
    int sum = 0;
    printf("Now choose the numbers that will be added: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }

    sum = arraySum(array, n);

    printf("The sum of the values is: %d\n", sum);

    return 0;
}

int arraySum(int array[], const int n) {
    int sum = 0;
    int *ptr = NULL;

    int *const arrayEnd = array + n;
    for (ptr = array; ptr < arrayEnd; ++ptr) {
        sum += *ptr;
    }

    return sum;
}
