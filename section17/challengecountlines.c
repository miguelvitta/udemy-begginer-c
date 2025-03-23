#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The following exit codes are used to indicate program status:
 * 0 - Correct program ending
 * 1 - Incorrect command line usage
 * 2 - Failed to open file
 * */

#define SIZE_STRING 1001

int readAndCountLines(FILE* fp);

int main(int argc, char* argv[]) {
    // error for wrong number of command line input
    if (argc != 2) {
        fprintf(stderr, "Error: Incorrect usage. Use %s <filename>\n", argv[0]);
        return 1;
    }

    printf(
        "This program takes a filename as input, then counts how many lines "
        "are there in the text and then prints it.\n");

    // file declaration and opening and error checking
    FILE* fp = NULL;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", argv[1]);
        return 2;
    }

    int result = readAndCountLines(fp);

    printf("The number of lines in the file is: %d\n", result);

    fclose(fp);
    fp = NULL;
    return 0;
}

int readAndCountLines(FILE* fp) {
    int count = 0;
    char ch = '\0';
    while ((ch = (char)fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    return count;
}

