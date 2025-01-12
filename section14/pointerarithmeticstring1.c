#include <stdio.h>

int main() {
    long int multiple[] = {15, 25, 35, 87};
    long int* p = multiple;

    for (long unsigned int i = 0; i < sizeof(multiple) / sizeof(multiple[0]);
         ++i) {
        printf("adress p+%ld (&multiple[%ld]): %llu *(p+%ld) value: %ld\n", i,
               i, (unsigned long long int)(p + i), i, *(p + i));
    }

    printf("\nType long occupies: %lu bytes\n", sizeof(long));

    return 0;
}
