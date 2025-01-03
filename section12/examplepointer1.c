#include <stdio.h>

int main() {
    
    int count = 10, x;
    int *int_pointer = NULL;

    int_pointer = &count;
    x = *int_pointer;

    printf("count = %i, x = %i\n", count, x);
    
    printf("adress of count is %p, and of x is %p.\n", &count, &x);

    return 0;
}
