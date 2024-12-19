#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
	enum gender {male, female};
    enum gender myGender;
    myGender = male;
    enum gender anotherGender = female;
    printf("%c %c %c %c\n", myGender, myGender, anotherGender, anotherGender);
}
