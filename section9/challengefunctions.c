#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

unsigned long long int getLLUInt(void);
void trimTrailingNewline(char *buffer, size_t *len);
bool isValidIntegerInput(const char *buffer, size_t len);
unsigned long long int getGCD(unsigned long long int number1,
                              unsigned long long int number2);
long double getLongDouble(void);
bool isValidFloatInput(const char *buffer, size_t len);
long double getSquareRootFloat(long double number4S);

int main() {
    printf("This program will have many functions, in sequence.\n");

    printf(
        "First, let's get 2 positive integers to calculate the Greatest Commom "
        "Divisor between them.\n");
    unsigned long long int number1 = getLLUInt();
    unsigned long long int number2 = getLLUInt();

    unsigned long long int gcd = getGCD(number1, number2);
    printf("The GCD of %llu and %llu is: %llu.\n", number1, number2, gcd);

    printf(
        "Now, let's get a number, float or integer to get it's absolute "
        "value.\n");
    long double number3 = getLongDouble();
    long double number3A = fabsl(number3);
    printf("The absolute value of the number you just wrote is: %Lf.\n",
           number3A);

    printf("Now lets do the square root of a positive number(float or int).\n");
    long double number4 = getLongDouble();
    long double number4S = getSquareRootFloat(number4);
    printf("The square root of %Lf is: %Lf.\n", number4, number4S);
}

unsigned long long int getLLUInt(void) {
    unsigned long long int number = 0;
    char buffer[100];

    while (true) {
        printf("Enter a valid integer: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            trimTrailingNewline(buffer, &len);

            if (isValidIntegerInput(buffer, len)) {
                sscanf(buffer, "%llu", &number);
                return number;
            }
        }
        printf("Invalid input. Please enter a valid positive integer.\n");
    }
}

void trimTrailingNewline(char *buffer, size_t *len) {
    if (*len > 0 && buffer[*len - 1] == '\n') {
        buffer[*len - 1] = '\0';
        (*len)--;
    }
}

bool isValidIntegerInput(const char *buffer, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (!isdigit(buffer[i])) {
            return false;
        }
    }
    return true;
}

unsigned long long int getGCD(unsigned long long int number1,
                              unsigned long long int number2) {
    if (number2 > number1) {
        unsigned long long int aux = number2;
        number2 = number1;
        number1 = aux;
    }

    while (number2 != 0) {
        unsigned long long int temp = number2;
        number2 = number1 % number2;
        number1 = temp;
    }

    return number1;
}

long double getLongDouble(void) {
    char buffer[100];
    while (true) {
        printf("Enter a valid floating number: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            trimTrailingNewline(buffer, &len);

            if (isValidFloatInput(buffer, len)) {
                long double number = 0;
                if (sscanf(buffer, "%Lf", &number) == 1) {
                    return number;
                }
            }
        }
        printf("Invalid input. Please try again.\n");
    }
}

bool isValidFloatInput(const char *buffer, size_t len) {
    bool decimalPointSeen = false;
    for (size_t i = 0; i < len; i++) {
        if (buffer[i] == '.') {
            if (decimalPointSeen) {
                return false;
            }
            decimalPointSeen = true;
        } else if (buffer[i] == '-') {
            if (i != 0) {
                return false;
            }
        } else if (!isdigit(buffer[i])) {
            return false;
        }
    }
    return true;
}

long double getSquareRootFloat(long double number4S) {
    if (number4S < 0) {
        printf("Negative input: No real square root.\n");
        return NAN;
    }

    long double result = number4S / 2.0;
    long double epsilon = 0.00001;

    while (fabsl(result * result - number4S) > epsilon) {
        result = 0.5 * (result + number4S / result);
    }

    return result;
}
