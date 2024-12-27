#include <stdio.h>
#include <stdbool.h>

void drawBoard();

int main() {
    int placar1 = 0;
    int placar2 = 0;
    bool choice = true;
    char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    while (choice) {
        printf("This is a game of tictactoe. Do you want to play a new game?\n(y/n): ");
        getchar();
        
    }

}
      
void drawBoard() {
    printf("\t\tTic Tac Toe\n\nPlayer 1 (X)   -   Player 2 (O)\n\n");

}
