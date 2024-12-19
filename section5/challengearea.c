#include <stdio.h>

int main()
{
    long double width = 4.5489625458;
    long double height = 18.5235149861;
    long double perimeter = 0.0;
    long double area = 0.0;

    printf("The width of the rectangle is: %Lf, and the height is: %Lf\n", width, height);
    perimeter = 2 *(height + width);
    area = width * height;
    printf("The perimeter of the rectangle is: %Lf, and the area is: %Lf\n", perimeter, area);


}
