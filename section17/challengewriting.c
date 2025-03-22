#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The following exit codes are used to indicate program status:
 * 0 - Correct program ending
 * 1 - Incorrect command line usage
 * 3 - Failed to open the file
 * 4 - Unexpected end of input while writing the strings
 * 5 - Error writing to file
 * 6 - Successfully wrote strings to file
 * 7 - Error when writing(see message for the specific code)
 * */

#define SIZE_STRING 1001

int readAndWriteStrings(FILE* fp, int numberStrings);

int main(int argc, char* argv[]) {
    // error for wrong command line input number
    if (argc != 3) {
        fprintf(
            stderr,
            "Error: Incorrect usage. Use %s <filename> <number of strings>\n",
            argv[0]);
        return 1;
    }

    // error checking for wrong type of command line input
    char* endptr = NULL;
    int numberStrings = (int)strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || numberStrings <= 0) {
        fprintf(stderr,
                "Error: Number of strings must be a positive integer\n");
        return 1;
    }

    printf(
        "This program takes a filename and a number of strings as input, then "
        "writes that number of strings to the file.\n");

    // file declaration and opening and error checking
    FILE* fp = NULL;
    fp = fopen(argv[1], "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", argv[1]);
        return 3;
    }

    int result = readAndWriteStrings(fp, numberStrings);
    if (result != 6) {
        fprintf(stderr, "Error writing to '%s' (code %d)\n", argv[1], result);
        return 7;
    }

    // finalization with closing and freeing memory
    fclose(fp);
    fp = NULL;
    return 0;
}

int readAndWriteStrings(FILE* fp, int numberStrings) {
    for (int i = 0; i < numberStrings; i++) {
        char buffer[SIZE_STRING];
        if (fgets(buffer, SIZE_STRING, stdin) == NULL) {
            if (feof(stdin)) {
                fprintf(stderr, "Unexpected end of file while writing\n");
                return 4;
            }
            if (ferror(stdin)) {
                fprintf(stderr, "Error writing to file\n");
                return 5;
            }
        } else {
            fprintf(fp, "%s", buffer);
        }
    }
    return 6;
}

