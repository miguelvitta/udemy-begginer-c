#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

void getNumber(long int *x);
void getInput(char strings[][SIZE], long int x);
void bubbleSort(char strings[][SIZE], long int x);

int main() {
    long int x = 0;
    getNumber(&x);
    if (x <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    char strings[x][SIZE];
    getInput(strings, x);
    bubbleSort(strings, x);

    return 0;
}

void getNumber(long int *x) {
    printf("Input number of strings.\n");
    char input[SIZE];
    long int number = 0;
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char *endPtr = NULL;
        number = strtol(input, &endPtr, 10);
        if (*endPtr == '\n' || *endPtr == '\0') {
            *x = number;
            printf("You entered the number %ld.\n", number);
            return;
        }
    }
    *x = 0;
}

void getInput(char strings[][SIZE], long int x) {
    printf("Input each of the strings: \n");
    for (long int i = 0; i < x; i++) {
        if (fgets(strings[i], SIZE - 1, stdin) != NULL) {
            strings[i][strcspn(strings[i], "\n")] = '\0';
        }
    }
    printf("The strings you wrote are: \n");
    for (long int i = 0; i < x; i++) {
        printf("%s\n", strings[i]);
    }
}

void bubbleSort(char strings[][SIZE], long int x) {
    char temp[SIZE];
    for (long int i = 0; i < x; i++) {
        for (long int j = 0; j < x - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                strncpy(temp, strings[j], sizeof(temp) - 1);
                strncpy(strings[j], strings[j + 1], sizeof(strings[j]) - 1);
                strncpy(strings[j + 1], temp, sizeof(strings[j + 1]) - 1);
            }
        }
    }
    printf("The strings reordered are: \n");
    for (long int i = 0; i < x; i++) {
        printf("%s\n", strings[i]);
    }
}
