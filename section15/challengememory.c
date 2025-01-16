#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLimit(int n);
size_t removeTrailing(size_t n, char *str);
void getString(char *str, int n);

int main() {
    int limit = 0;
    while (limit == 0) {
        limit = getLimit(limit);
    }

    char *string = NULL;
    string = malloc(sizeof *string * limit);
    if (!string) {
        free(string);
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }

    getString(string, limit);

    printf("%s\n", string);

    free(string);

    return 0;
}

int getLimit(int n) {
    char buffer[100];
    printf("Write the number of characters that will be the limit: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        size_t len = strlen(buffer);
        len = removeTrailing(len, buffer);

        for (size_t i = 0; i < len; i++) {
            if (!isdigit(buffer[i])) {
                fprintf(stderr, "\nThis is not a valid number.\n");
                return 0;
            }
            n = n * 10 + (buffer[i] - '0');
            if (n < 0) {
                fprintf(stderr, "\nNumber is too large.\n");
                return 0;
            }
        }
    }
    return n;
}

size_t removeTrailing(size_t n, char *str) {
    if (n > 0 && str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n--;
    }
    return n;
}

void getString(char *str, int n) {
    printf("Enter the string: ");
    if (fgets(str, n, stdin) != NULL) {
    } else {
        fprintf(stderr, "Error reading the string");
    }
}

