#include <stdbool.h>
#include <stdio.h>

void cleanInputBuffer();
void drawBoard(char *board);
void markBoard(char *board, bool *isPlayer1);
int getValidInput();
bool checkPlace(char *board, int place);


int main() {
    bool choice = true;
    bool isPlayer1 = true;
    char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    while (choice) {
        printf(
            "This is a game of tictactoe. Do you want to play a new "
            "game?\n(y/n): ");
        getchar();
        cleanInputBuffer();
        drawBoard(board);
        markBoard(board, &isPlayer1);
    }
    return 0;
}

void cleanInputBuffer() {
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Keep reading until a newline or EOF is encountered
    }
}

void drawBoard(char *board) {
    printf("\n\n\t\t\tTic Tac Toe\n\n\t\tPlayer 1 (X)   -   Player 2 (O)\n\n");
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
                printf("\t \t|\t \t|\t \t\n");  // line without numbers
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
    }
    *isPlayer1 = !(*isPlayer1);
}

int getValidInput() {

}

bool checkPlace(char *board, int place) {
    if (board[place - 1] == 'X' || board[place - 1] == 'O') {
        printf("Invalid place, this position was already chosen.\n");
        return false;   
    }
    return true;
}
