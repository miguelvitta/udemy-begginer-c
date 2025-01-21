#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char name[101];
    Date hireDate;
    double salary;
} Employee;

int main() {
    Employee emp1 = {"Miguel", {19, 01, 2025}, 1000000.99};
    
    printf("\n\tName: %s", emp1.name);
    printf("\n\tDate: %d/%d/%d", emp1.hireDate.day, emp1.hireDate.month, emp1.hireDate.year % 100);
    printf("\n\tSalary: $%.2lf\n", emp1.salary);

    return 0;
}
