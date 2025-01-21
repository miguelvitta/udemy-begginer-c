#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char name[SIZE];
    Date hireDate;
    int salary;
} Employee;

void getString(char *str);
size_t removeTrailing(size_t n, char *str);
int getInt();

int main() {
    Employee emp1;

    printf("Write the name of the Employee: ");
    getString(emp1.name);

    printf("Write the date he/she was hired, as follows: \n");
    printf("Day: ");
    emp1.hireDate.day = -1;
    while (emp1.hireDate.day < 1 || emp1.hireDate.day > 31) {
        emp1.hireDate.day = getInt();
    }
    printf("Month: ");
    emp1.hireDate.month = -1;
    while (emp1.hireDate.month < 1 || emp1.hireDate.month > 12) {
        emp1.hireDate.month = getInt();
    }
    printf("Year: ");
    emp1.hireDate.year = -1;
    while (emp1.hireDate.year < 1990 || emp1.hireDate.year > 2100) {
        emp1.hireDate.year = getInt();
    }

    printf("Write the salary, in cents: ");
    emp1.salary = 0;
    while (emp1.salary == 0) {
        emp1.salary = getInt();
    }

    printf(
        "The data on the Employee is:\n\tName: %s\n\tDate Hired: "
        "%02d/%02d/%d\n\tSalary: %02d,%d\n",
        emp1.name, emp1.hireDate.day, emp1.hireDate.month,
        emp1.hireDate.year % 100, emp1.salary / 100, emp1.salary % 100);

    return 0;
}

void getString(char *str) {
    if (fgets(str, SIZE, stdin) != NULL) {
        size_t len = strlen(str);
        len = removeTrailing(len, str);

        if (len == 0) {
            fprintf(stderr, "\nInput cannont be empty. Try again: ");
            getString(str);
        }
    } else {
        fprintf(stderr, "Error reading the string.\n");
    }
}

size_t removeTrailing(size_t n, char *str) {
    if (n > 0 && str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n--;
    }
    return n;
}

int getInt() {
    int n = 0;
    char buffer[SIZE];
    if (fgets(buffer, SIZE, stdin) != NULL) {
        size_t len = strlen(buffer);
        len = removeTrailing(len, buffer);

        for (size_t i = 0; i < len; i++) {
            if (!isdigit(buffer[i])) {
                fprintf(stderr, "\nThis is not a valid number.\n");
                return 0;
            }
            n = n * 10 + (buffer[i] - '0');
            if (n < 0) {
                fprintf(stderr, "\nNumber is too large.\n");
                return 0;
            }
        }
    }
    return n;
}

