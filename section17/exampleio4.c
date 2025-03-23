#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Incorrect usage. Use %s <filename>\n", argv[0]);
        return 1;
    }

    printf("This program takes a filename as input and then writes to it\n");

    FILE* fp = NULL;
    fp = fopen(argv[1], "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", argv[1]);
        return 2;
    }

    int ch = 0;

    for (ch = 33; ch <= 100; ch++) {
        fputc(ch, fp);
    }

    fclose(fp);
    fp = NULL;
    return 0;
}

