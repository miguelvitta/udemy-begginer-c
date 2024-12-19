#include <stdio.h>

int main(int argc, char *argv[])
{
    int nArgs = argc;
    char *argument0= argv[0];
    char *argument1= argv[1];

    printf("Number of arguments: %d\n", nArgs);
    printf("Argument 0 is the program name: %s\n", argument0);
    printf("Argument 1 is the command line argument: %s\n", argument1);
    
    return 0;
}
