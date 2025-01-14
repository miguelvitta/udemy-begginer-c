#include <stdio.h>
#include <string.h>

#define SIZE 1001

void getString(char *str);
int getSize(const char *str);

int main() {
    char string[SIZE];
    getString(string);

    int sizeString = getSize(string);
    printf("\n%d\n", sizeString);

    return 0;
}

void getString(char *str) {
    printf("Write something (1-1000 size): ");
    if (fgets(str, SIZE, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

int getSize(const char *str) {
    const char *lastAdress = str;
    while (*lastAdress) {
        ++lastAdress;    
    }
    return lastAdress - str;
}
