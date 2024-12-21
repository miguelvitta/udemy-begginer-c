#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int answer = 0;
    srand((time(NULL)));
    int random = 0;
    do
    {
        random = rand() % 100;
    }
    while(random > 20);
    printf("This is a guessing game.\nI have chosen a number between 0 and 20 which you must guess.\n");

    for(int i = 5; i > 0 && answer != random; i--) {
        printf("You have %d tries left\n", i);

        bool validInput = false;
        while(!validInput) {
            printf("Enter a guess: ");
            if(scanf("%d", &answer) != 1 || answer < 0 || answer > 20) {
                printf("Invalid input. Please enter a number between 0 and 20.\n");
                while (getchar() != '\n');
            } else {
                validInput = true;
            }
        }
        if(answer > random) {
                printf("Sorry, %d is wrong, my number is less than that.\n", answer);
        }
        else {
            if(answer < random){
                printf("Sorry, %d is wrong, my number is more than that.\n", answer);
            }
        }
    }
    if(answer == random) {
        printf("Congratulations! You guessed it! %d is the right number.\n", answer);
    }
    else {
        printf("That's a pity, you had 5 guesses but you failed.\n");
    }
    

    return 0;
}
