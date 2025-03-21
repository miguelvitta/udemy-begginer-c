#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_STRING 1001
#define SIZE_INT 20
#define SIZE_NAME 100

struct item {
    char* itemName;
    int quantity;
    double price;
    double amount;  // quantity * price
};

void getString(char* str);
size_t removeTrailing(size_t len, char* str);
int getInt();
void readItem(struct item* item);
void printItem(struct item* item);

int main() {
    struct item item = {NULL, 0, 0.0, 0.0};
    struct item* pItem = NULL;

    pItem = &item;

    pItem->itemName = malloc(SIZE_NAME * sizeof(char));

    if (pItem == NULL) {
        return 1;
    }

    readItem(pItem);

    printItem(pItem);

    free(pItem->itemName);

    return 0;
}

void readItem(struct item* item) {
    printf("Enter product name: ");
    getString(item->itemName);

    printf("\nEnter quantity: ");
    item->quantity = getInt();

    printf("\nEnter price: ");
    scanf("%lf", &item->price);

    item->amount = (double)item->quantity * item->price;
}


void getString(char* str) {
    int valid = 0;
    while (!valid) {
        if (fgets(str, SIZE_STRING, stdin) != NULL) {
            size_t len = strlen(str);
            len = removeTrailing(len, str);
            if (len > 0) {
                valid = 1;
            } else {
                fprintf(stderr, "\nInput cannot be empty. Try again: ");
            }
        } else {
            fprintf(stderr, "\nError reading the string.\n");
        }
    }
}

size_t removeTrailing(size_t len, char* str) {
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    return len;
}

int getInt() {
    int number = 0;
    int valid = 0;
    char buffer[SIZE_INT];
    printf("Enter a integer: ");
    while (!valid) {
        if (fgets(buffer, SIZE_INT, stdin) != NULL) {
            size_t len = strlen(buffer);
            len = removeTrailing(len, buffer);
            if (len > 0) {
                valid = 1;
                for (size_t i = 0; i < len; i++) {
                    if (!isdigit(buffer[i])) {
                        fprintf(stderr, "\nThis is not a valid number.\n");
                    }
                    number = number * 10 + (buffer[i] - '0');
                    if (number > INT_MAX) {
                        fprintf(stderr, "\nNumber is too large.\n");
                    }
                }
            } else {
                fprintf(stderr, "\nInput cannot be empty. Try again: ");
            }
        } else {
            fprintf(stderr, "\nError reading the string.\n");
        }
    }
    return number;
}


void printItem(struct item* item) {
    printf("\nName: %s", item->itemName);
    printf("\nPrice: %.2lf", item->price);
    printf("\nQuantity: %d", item->quantity);
    printf("\nTotal Amount: %.2lf\n", item->amount);
}

