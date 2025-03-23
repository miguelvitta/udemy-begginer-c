#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
    FILE* fp;

    fp = fopen("file.txt", "w+");
    if (fp != NULL) {
        fputs("Hello, how are you?", fp);
    }

    rewind(fp);

    fscanf(fp, "%s %s %s %s", str1, str2, str3, str4);

    printf("Read String 1: |%s|\n", str1);
    printf("Read String 2: |%s|\n", str2);
    printf("Read String 3: |%s|\n", str3);
    printf("Read String 4: |%s|\n", str4);

    fclose(fp);


    return 0;
}
