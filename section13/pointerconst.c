#include <stdio.h>

int main() {
    int count = 43;
    int *const pcount = &count; // pointer adress cannot be changed
    int count1 = 34;
    const int *pcount1 = &count1; // value cannot be changed
    
    printf("----------------------------------------\n");
    printf("Adress of count: %p\n", &count);
    printf("Value of count: %d\n", count);
    printf("Value that pcount is pointing to: %d\n", *pcount);
    printf("Adress of count1: %p\n", &count1);
    printf("Value of count1: %d\n", count1);
    printf("Value that pcount1 is pointing to: %d\n", *pcount1);
    printf("----------------------------------------\n");

    count = 434; // I can modify the variables 
    count1 = 343; // I can modify the variables 

    printf("----------------------------------------\n");
    printf("Adress of count: %p\n", &count);
    printf("Value of count: %d\n", count);
    printf("Value that pcount is pointing to: %d\n", *pcount);
    printf("Adress of count1: %p\n", &count1);
    printf("Value of count1: %d\n", count1);
    printf("Value that pcount1 is pointing to: %d\n", *pcount1);
    printf("----------------------------------------\n");

    *pcount = 43;
    // *pcount1 = 34; // read only variable

    printf("----------------------------------------\n");
    printf("Adress of count: %p\n", &count);
    printf("Value of count: %d\n", count);
    printf("Value that pcount is pointing to: %d\n", *pcount);
    printf("Adress of count1: %p\n", &count1);
    printf("Value of count1: %d\n", count1);
    printf("Value that pcount1 is pointing to: %d\n", *pcount1);
    printf("----------------------------------------\n");

    int count2 = 98;
    // pcount = &count2; // const-qualified type
    pcount1 = &count2;

    printf("----------------------------------------\n");
    printf("Adress of count: %p\n", &count);
    printf("Value of count: %d\n", count);
    printf("Value that pcount is pointing to: %d\n", *pcount);
    printf("Adress of count1: %p\n", &count1);
    printf("Value of count1: %d\n", count1);
    printf("Value that pcount1 is pointing to: %d\n", *pcount1);
    printf("----------------------------------------\n");

    return 0;
}
