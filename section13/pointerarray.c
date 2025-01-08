#include <stdio.h>

int main() {
    // both ways are equivalent 
    int values[100] = {1};
    int *valuesPtr = NULL;
    valuesPtr = values;

    int values1[100] = {2};
    int *values1Ptr = NULL;
    values1Ptr = &values1[0];

    printf("The first value of values is %d\n", *valuesPtr);
    printf("The first value of values1 is %d\n", *(values1Ptr));

    return 0;
}
