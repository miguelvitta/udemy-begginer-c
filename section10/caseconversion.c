#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char substring[40];

    printf("Enter the string to be searched (< 100 characters): ");
    scanf("%s", text);

    printf("Enter the string sought (< 40 characters)");
    scanf("%s", substring);

    printf("\nFirst string entered: \n\"%s\"\n", text);
    printf("Second string entered: \"%s\"\n", substring);

    for (int i = 0; (text[i] = (char)toupper(text[i])) != '\0'; i++)
        ;
    for (int i = 0; (substring[i] = (char)toupper(substring[i])) != '\0'; i++)
        ;

    printf("The second string %s found in the first.\n",
           ((strstr(text, substring) == NULL) ? "was not" : "was"));

    return 0;
}
