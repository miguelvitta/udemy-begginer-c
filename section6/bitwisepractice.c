#include <stdio.h>

int main()
{
    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101

    int resultAnd = a & b; // 0000 1100 = 12
    printf("resultAnd = %d\n", resultAnd);

    int resultOr = a | b; // 0011 1101 = 61
    printf("resultOr = %d\n", resultOr);

    int resultXOR = a ^ b; // 0011 0001 = 49
    printf("resultXOR = %d\n", resultXOR);

    int resultInv = ~a; // 1100 0011 = -61
    printf("resultInv = %d\n", resultInv);

    int resultShiftLeft = a << 2; // 1111 0000 = 240
    printf("resultShiftLeft = %d\n", resultShiftLeft);

    int resultShiftRight = a >> 2; // 0000 1111 = 15
    printf("resultShiftRight = %d\n", resultShiftRight);

    return 0;
}
