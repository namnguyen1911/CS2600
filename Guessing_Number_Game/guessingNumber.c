#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void guessingGame();
int changeMax();


int main() {
    char answer = '\0';
    int maxNumber = 10;
    bool check = true;

    //Prompt the users select the provided options
    while(check) {
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");
        scanf("%c%*c", &answer);

        switch(answer) {
            case '1': guessingGame(maxNumber); break;
            case '2': maxNumber = changeMax(); break;
            case '3': check = false; break;
            default: printf("Invalid input!\n");
        }

    }
    


    return 0;
}

void guessingGame(int maxNumber) {
    

}

int changeMax() {
    return 0;
}

