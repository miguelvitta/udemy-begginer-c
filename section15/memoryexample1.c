#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = NULL;
    size_t size = 15;

    str = malloc(sizeof *str * size);
    if (!str) {
        free(str);
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }
    strlcpy(str, "jason", size);
    printf("String = %s, adress = %p\n", str, (void *)str);

    size = 25;
    char *temp = NULL;
    temp = realloc(str, sizeof *str * size);
    if (!temp) {
        free(str);
        fprintf(stderr, "Memory reallocation has failed\n");
        return 1;
    }
    str = temp;
    strlcat(str, ".com", size);
    printf("String = %s, adress = %p\n", str, (void *)str);

    free(str);

    return 0;
}

