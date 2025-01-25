#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee employees[5] = {{101, "John Doe", 50000.0},
                                    {102, "Jane Smith", 55000.0},
                                    {103, "Emily Davis", 60000.0},
                                    {104, "Chris Johnson", 45000.0},
                                    {105, "Anna Brown", 70000.0}};

    for (int i = 0; i < 5; i++) {
        printf("Employee %d: ID=%d, Name=%s, Salary=%.2f\n", i + 1,
               employees[i].id, employees[i].name, employees[i].salary);
    }

    return 0;
}

