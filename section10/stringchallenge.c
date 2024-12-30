#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SIZE 1001

void getOnlyLength();
void getStringInput(char *str);
int getStringLength(const char *str, int count);
void joinTwoStrings();
void determineIfEquals();

int main() {
    bool valid = true;
    while (valid) {
        printf(
            "----------------------------------------------------------------\n"
            "This is a program with three functions:\n"
            " - [1] Get the length of a string;\n"
            " - [2] Concatenate two strings;\n"
            " - [3] Determine if two strings are equal;\n"
            "Type 1, 2, or 3 for each program and any other input to exit.\n"
            "----------------------------------------------------------------"
            "\n");

        char input = '0';
        input = (char)getchar();
        while (getchar() != '\n') {
            ;  // this weird addition of curly brackets is to appease the linter
        }
        switch (input) {
            case '1':
                getOnlyLength();
                break;
            case '2':
                joinTwoStrings();
                break;
            case '3':
                determineIfEquals();
                break;
            default:
                valid = false;
                printf("Goodbye, until the next time!\n");
        }
    }
}

void getOnlyLength() {
    char strL[SIZE];
    int countL = 0;
    getStringInput(strL);
    countL = getStringLength(strL, countL);
    printf("The length of \"%s\" is %d.\n", strL, countL);
}

void getStringInput(char *str) {
    printf("Write a sentence (up to 1000 characters) to get its length: ");
    if (fgets(str, SIZE - 1, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

int getStringLength(const char *str, int count) {
    count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

void joinTwoStrings() {
    char str1[SIZE];
    char str2[SIZE];

    getStringInput(str1);
    getStringInput(str2);
    int count1 = 0;
    int count2 = 0;
    count1 = getStringLength(str1, count1);
    count2 = getStringLength(str2, count2);

    int count3 = count1 + count2 + 1;
    char str3[count3];

    for (int i = 0; i < count1; i++) {
        str3[i] = str1[i];
    }

    for (int i = 0, j = count1; j < count3; i++, j++) {
        str3[j] = str2[i];
    }

    printf("The joining of \n\"%s\" and \n\"%s\" is \n\"%s\".\n", str1, str2,
           str3);
}

void determineIfEquals() {
    char str1[SIZE];
    char str2[SIZE];

    getStringInput(str1);
    getStringInput(str2);
    int count1 = 0;
    int count2 = 0;
    count1 = getStringLength(str1, count1);
    count2 = getStringLength(str2, count2);

    if (count1 != count2) {
        printf(
            "These strings aren't even of the same size, much less equal.\n");
        return;
    }

    for (int i = 0; i < count1; i++) {
        if (str1[i] != str2[i]) {
            printf("The strings are not equal.\n");
            return;
        }
    }

    printf("The strings are equal.\n");
}
