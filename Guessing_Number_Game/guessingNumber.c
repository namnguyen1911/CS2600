#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
    time_t t;
    int rightNumber = 0;
    bool check = true;
    int ans = 0;
    int buffer = 0;


    srand((unsigned) time(&t));
    rightNumber = (rand() % maxNumber) + 1;

    while(check) {
        printf("Enter a number from 1 to %d\n", maxNumber);

        if(scanf("%d%*c", &ans) != 1) {
            buffer = getchar();
            if(buffer == 'q') {
                buffer = getchar();
                break;
            }
            else {
                printf("Invalid input!\n");
                while((buffer = getchar()) != EOF && buffer != '\n');
            }
        }
        
        else if(ans < rightNumber) {
            printf("Your guess is too low\n");
        }
        else if (ans > rightNumber) {
            printf("Your guess is too large\n");
        }
        else if (ans == rightNumber) {
            printf("You won!\n");
            check = false;
        }
        
    }


}

int changeMax() {
    int maxNumber = 0;
    printf("You can only enter max number up to %d\n", INT_MAX);
    printf("Enter your max number:\n");
    scanf("%d%*c",&maxNumber);
    return maxNumber;
}

