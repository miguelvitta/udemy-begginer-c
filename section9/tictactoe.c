#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool getUserChoice();
void cleanInputBuffer();
void drawBoard(char *board, int *scoreTally);
void markBoard(char *board, bool *isPlayer1);
int getValidInput();
bool checkPlace(const char *board, int place);
int checkForWin(const char *board);

int main() {
    bool isPlayer1 = true;
    char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int scoreTally[2] = {0, 0};
    while (getUserChoice()) {
        for (int i = 0; i < 9; i++) {
            board[i] = (char)('1' + i);
        }

        while (checkForWin(board) == -1) {
            drawBoard(board, scoreTally);
            markBoard(board, &isPlayer1);
        }

        drawBoard(board, scoreTally);
        int result = checkForWin(board);
        if (result == 1) {
            printf("Player %d wins!\n", isPlayer1 ? 2 : 1);
            if (isPlayer1) {
                scoreTally[1]++;  // Player 2 wins
            } else {
                scoreTally[0]++;  // Player 1 wins
            }
        } else if (result == 0) {
            printf("It's a draw!\n");
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}

bool getUserChoice() {
    char input = '\0';
    while (1) {
        printf("Do you want to play a new game? (y/n): ");
        input = (char)getchar();
        cleanInputBuffer();

        if (input == 'y') {
            return true;
        }
        if (input == 'n') {
            return false;
        }

        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
}

void cleanInputBuffer() {
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void drawBoard(char *board, int *scoreTally) {
    printf(
        "\n\n\t\t\tTic Tac Toe\n\n\t\tPlayer 1 (X): %d wins  -   Player 2 (O): "
        "%d wins\n\n",
        scoreTally[0], scoreTally[1]);
    for (int i = 0, j = 0; i < 12; i++) {
        if (i == 1 || i == 5 || i == 9) {
            printf("\t%c\t|\t%c\t|\t%c\t\n", board[j], board[j + 1],
                   board[j + 2]);
            j += 3;
        } else {
            if (i == 3 || i == 7) {
                printf(
                    "----------------------------------------------------------"
                    "\n");
            } else {
                printf("\t \t|\t \t|\t \t\n");
            }
        }
    }
    printf("\n\n");
}

void markBoard(char *board, bool *isPlayer1) {
    int place = 0;
    bool valid = false;
    while (!valid) {
        place = getValidInput();
        valid = checkPlace(board, place);
        if (!valid) {
            printf("That place is already taken. Try again.\n");
        }
    }
    board[place - 1] = *isPlayer1 ? 'X' : 'O';
    *isPlayer1 = !(*isPlayer1);
}

int getValidInput() {
    int place = 0;
    char input[10];  // Buffer to store user input
    char *endPtr =
        NULL;  // Pointer to check invalid characters during conversion

    while (1) {
        printf("Choose a place on the board (1-9): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Convert input to integer using strtol
            place = (int)strtol(input, &endPtr, 10);

            // Check for valid conversion and bounds
            if (endPtr != input && *endPtr == '\n' && place >= 1 &&
                place <= 9) {
                return place;
            }
        }
        printf("Invalid input. Please enter a number between 1 and 9.\n");
    }
}

bool checkPlace(const char *board, int place) {
    if (board[place - 1] == 'X' || board[place - 1] == 'O') {
        return false;
    }
    return true;
}

int checkForWin(const char *board) {
    const int winningCombinations[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                                           {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                                           {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; i++) {
        int a = winningCombinations[i][0];
        int b = winningCombinations[i][1];
        int c = winningCombinations[i][2];
        if (board[a] == board[b] && board[b] == board[c]) {
            return 1;  // Win
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return -1;  // Game in progress
        }
    }

    return 0;  // Draw
}
