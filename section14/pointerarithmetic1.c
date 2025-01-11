#include <stdio.h>

int main() {
    int values[10] = {0};
    int *valuesPtr = &values[0];
    
    values[9] = 10;
    printf("The value on the 10º position is: %d\n", values[9]);
    
    *(valuesPtr + 9) = 27;
    printf("The value on the 10º position is: %d\n", values[9]);

    return 0;
}
