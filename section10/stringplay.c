#include <stdio.h>

int main() {

    printf("For \" you write \\\".\n");

    printf("The character \\0 is used to terminate a string.\n");

    char str1[] = "To be or not to be";
    char str2[] = ", that's the question";

    unsigned int count = 0;

    while (str1[count] != '\0') {
        count++;
    }

    printf("The length of the string is \"%s\" is %d characters.\n", str1, count);

    count = 0;

    while (str2[count] != '\0') {
        count++;
    }

    printf("The length of the string is \"%s\" is %d characters.\n", str2, count);

}
