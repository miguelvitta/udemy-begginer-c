#include <stdio.h>
#include <string.h>

#define SIZE 1001

void getInput(char *str);
void copyString1(char to[], const char from[]);
void copyString2(char *to, char *from);

int main() {
    char stringsa[SIZE];

    getInput(stringsa);
    char string1[SIZE];
    copyString1(string1, stringsa);
    printf("\n\n%s\n\n", string1);

    char stringsb[SIZE];
    getInput(stringsb);
    char string2[SIZE];
    copyString2(string2, stringsb);
    printf("\n\n%s\n\n", string2);
    return 0;
}

void getInput(char *str) {
    printf("Write your string(1-1000): ");
    if (fgets(str, SIZE - 1, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

void copyString1(char to[], const char from[]) {
    int i = 0;
    for (; from[i] != '\0'; ++i) {
        to[i] = from[i];
    }
    to[i] = '\0';
}

void copyString2(char *to, char *from) {
    while (*from) {
        *to++ = *from++;
    }
    *to = '\0';
}

