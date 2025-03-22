#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING 1001

void getStreamString(char* buffer, FILE* fp);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* fp = NULL;
    char* buffer = NULL;

    buffer = malloc(sizeof(char) * SIZE_STRING);
    if (buffer == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        return 2;
    }
    printf(
        "This program reads a file then prints it's content. String by "
        "string.\n");

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "File %s failed to open\n", argv[1]);
        free(buffer);
        return 3;
    }

    getStreamString(buffer, fp);

    fclose(fp);
    fp = NULL;

    free(buffer);
    return 0;
}

void getStreamString(char* buffer, FILE* fp) {
    int valid = 0;
    while (!valid) {
        if (fgets(buffer, SIZE_STRING, fp) == NULL) {
            if (feof(fp)) {
                return;
            }
            if (ferror(fp)) {
                fprintf(stderr, "Error reading file\n");
                return;
            }
        } else {
            printf("%s", buffer);
        }
    }
}

