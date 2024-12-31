#include <ctype.h>
#include <stdio.h>

int main() {
    char buff[100];
    int nLetters = 0;
    int nDigits = 0;
    int nPunct = 0;

    printf("Enter an interesting string of less than %s characters: ", "100");
    scanf("%s", buff);

    int i = 0;

    while (buff[i]) {
        if (isalpha(buff[i])) {
            ++nLetters;
        } else {
            if (isdigit(buff[i])) {
                ++nDigits;
            } else {
                if (ispunct(buff[i])) {
                    ++nPunct;
                }
            }
        }
        i++;
    }

    printf(
        "\nYour string contains %d letters, %d digits and %d puntuaction "
        "characters.\n",
        nLetters, nDigits, nPunct);

    return 0;
}
