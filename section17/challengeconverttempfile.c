#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define TEMP_FILENAME "tempFile.txt"

void writeToTempFile(FILE* filePtr, FILE* tempFilePtr);

int main(int argc, char* argv[]) {
    // error for wrong number of command line input
    if (argc != 2) {
        fprintf(stderr, "Error: Incorrect usage. Use %s <filename>\n", argv[0]);
        return 1;
    }

    printf(
        "This program takes a filename as input, converts all characters to "
        "UPPERCASE and puts the output to a new file. Then it will rename the "
        "temporary file to the original name and delete the original.\n");

    // file declaration and opening and error checking
    FILE* filePtr = NULL;
    filePtr = fopen(argv[1], "r");
    if (filePtr == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", argv[1]);
        return 2;
    }

    FILE* tempFilePtr = NULL;
    tempFilePtr = fopen(TEMP_FILENAME, "w+");
    if (tempFilePtr == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", TEMP_FILENAME);
        return 3;
    }

    writeToTempFile(filePtr, tempFilePtr);

    fclose(tempFilePtr);
    fclose(filePtr);

    if (remove(argv[1]) != 0) {
        fprintf(stderr, "Failed to remove original file '%s'\n", argv[1]);
        return 4;
    }

    if (rename(TEMP_FILENAME, argv[1]) != 0) {
        fprintf(stderr, "Failed to rename '%s' to '%s'\n", TEMP_FILENAME, argv[1]);
        fclose(filePtr);
        return 5;
    }

    tempFilePtr = NULL;
    filePtr = NULL;
    return 0;
}

void writeToTempFile(FILE* filePtr, FILE* tempFilePtr) {
    int buffer = 0;
    while ((buffer = fgetc(filePtr)) != EOF) {
        if (islower(buffer)) {
            buffer = toupper(buffer);
        }
        fputc(buffer, tempFilePtr);
    }
}

