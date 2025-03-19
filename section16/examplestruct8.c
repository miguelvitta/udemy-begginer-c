#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING 1001

struct namect {
    char* fname;
    char* lname;
    int letters;
};

void getinfo(struct namect* pst);
void getString(char* str);
size_t removeTrailing(size_t len, char* str);

int main() {
    struct namect person;
    getinfo(&person);
    printf("First name: %s\n", person.fname);
    printf("Last name: %s\n", person.lname);
    printf("Total letters: %d\n", person.letters);

    free(person.fname);
    free(person.lname);
    return 0;
}

void getinfo(struct namect* pst) {
    char temp[SIZE_STRING];
    printf("Enter your first name: ");
    getString(temp);

    pst->fname = malloc(strlen(temp) + 1);
    strcpy(pst->fname, temp);

    printf("Enter your second name: ");
    getString(temp);
    pst->lname = malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);

    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void getString(char* str) {
    int valid = 0;
    while (!valid) {
        if (fgets(str, SIZE_STRING, stdin) != NULL) {
            size_t len = strlen(str);
            len = removeTrailing(len, str);
            if (len > 0) {
                valid = 1;
            } else {
                fprintf(stderr, "\nInput cannot be empty. Try again: ");
            }
        } else {
            fprintf(stderr, "\nError reading the string.\n");
        }
    }
}

size_t removeTrailing(size_t len, char* str) {
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    return len;
}

