#include <stdio.h>
#include <string.h>

int main() {
    char multiple[] = "a string";
    char *p = multiple;

    for (long unsigned int i = 0; i < strnlen(multiple, sizeof(multiple));
         ++i) {
        printf(
            "multiple[%ld] = %c *(p+%ld) = %c &multiple[%ld] = %p p+%ld = %p\n",
            i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
    }

    return 0;
}

