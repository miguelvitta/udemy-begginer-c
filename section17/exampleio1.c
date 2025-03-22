#include <stdio.h>

int main() {
    int x = FOPEN_MAX;

    printf("The max number of files that can be open at the same time is: %d\n", x);

    FILE* fp;
    int c;

    fp = fopen("file.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "File %s failed to open\n", "file.txt");
        return -1;
    }

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    printf("\n");

    fclose(fp);
    fp = NULL;

    return 0;
}
