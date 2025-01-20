#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[101];
    char date[15];
    float salary;
} Employee;

int main() {
    Employee emp1 = {"Miguel", "01/19/25", 1000000.99};
    
    printf("\n\tName: %s", emp1.name);
    printf("\n\tDate: %s", emp1.date);
    printf("\n\tSalary: $%.2f\n", emp1.salary);

    return 0;
}
