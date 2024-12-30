#include <stdio.h>
#include <string.h>

#define SIZE 1001

void getInput(char *str);
void reverseString(char *str, size_t len);

int main() {
    printf("This program will reverse a string.\n");
    char str[SIZE];
    getInput(str);
    size_t len = strlen(str);
    reverseString(str, len);
    return 0;
}

void getInput(char *str) {
    printf("Write your string(1-1000): ");
    if (fgets(str, SIZE - 1, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

void reverseString(char *str, size_t len) {
    char strR[len + 1];
    int x = (int)len;
    for (int i = 0, j = x - 1; j >= 0; i++, j--) {
        strR[i] = str[j];
    }
    strR[x] = '\0';
    printf("The original string is: \n\"%s\"\n and the reversed is: \n\"%s\"\n",
           str, strR);
}
