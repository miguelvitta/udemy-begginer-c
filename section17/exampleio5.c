#include <stdio.h>

#define SIZE_STRING 1001

void writeStringsToFile(FILE* filePtr);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Incorrect usage. Use %s <filename>\n", argv[0]);
        return 1;
    }

    printf("This program takes a filename as input and then writes to it\n");

    FILE* filePtr = NULL;
    filePtr = fopen(argv[1], "w+");
    if (filePtr == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", argv[1]);
        return 2;
    }

    writeStringsToFile(filePtr);

    fclose(filePtr);
    filePtr = NULL;
    return 0;
}

void writeStringsToFile(FILE* filePtr) {
    fputs("Let's make this a simple program ", filePtr);
    fputs("and move on.\n", filePtr);
}

