#include <stdio.h>

int main() {
    FILE* filePointer = NULL;
    int len = 0;

    filePointer = fopen("file.txt", "r");
    if (filePointer == NULL) {
        perror("Error reading file\n");
        return 1;
    } 

    fseek(filePointer, 0, SEEK_END);

    len = ftell(filePointer);

    fclose(filePointer);

    printf("The total size of this file is: %d bytes\n", len);

    return 0;
}
