#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void guessingGame(int maxNumber);
int changeMax();
void maxNumber(int maxNumber);
void writeFile(int maxNumber);


int main() {
    //Declaration and initialization
    char answer = '\0';
    int maxNumber = 10;
    bool check = true;

    //Prompt the users select the provided options
    while(check) {
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");
        scanf("%c%*c", &answer);

        //Option menu
        switch(answer) {
            case '1': guessingGame(maxNumber); break;
            case '2': maxNumber = changeMax(); writeFile(maxNumber); break;
            case '3': check = false; printf("Thank for playing the game"); break;
            default: printf("Invalid input!\n");
        }
    }
    return 0;
}


void guessingGame(int maxNumber) {
    //Declaration and initialization
    time_t t;
    int rightNumber = 0;
    bool check = true;
    int ans = 0;
    int buffer = 0;

    //Create a random number from 1 to maxNumber
    srand((unsigned) time(&t));
    rightNumber = (rand() % maxNumber) + 1;


    while(check) {
        printf("Enter a number from 1 to %d\n", maxNumber);

        //Check character input
        if(scanf("%d%*c", &ans) != 1) {
            buffer = getchar();
            //If input is q, break out of the loop
            if(buffer == 'q') {
                buffer = getchar();
                break;
            }
            //If input is not q but other character, clear buffer
            else {
                printf("Invalid input!\n");
                while((buffer = getchar()) != EOF && buffer != '\n');
            }
        }
        //If input is an integer less than the correct number
        else if(ans < rightNumber) {
            printf("Your guess is too low\n");
        }
        //If input is an integer greater than the correct number
        else if (ans > rightNumber) {
            printf("Your guess is too large\n");
        }
        //If input is equal to the correct number
        else if (ans == rightNumber) {
            printf("You won!\n");
            check = false;
        }
        
    }


}

int changeMax() {
    //Declaration and initialization
    int maxNumber = 0;
    bool check = true;

    printf("You can only enter max number up to %d\n", INT_MAX);
    printf("Enter your max number:\n");

    //Check input
    while(check) {
        //If inputs are characters, clear the buffer
        if(scanf("%d%*c",&maxNumber) != 1) {
            printf("Invalid input!\n");
            while((maxNumber = getchar()) != EOF && maxNumber != '\n');
        }
        //If input digits are greater than INT_MAX or negative
        else if(maxNumber > INT_MAX || maxNumber < 0) {
            printf("Your enter number must be less than %d and positive!\n",INT_MAX);
            continue;
        }
        //If intput digits are from 0 to INT_MAX 
        else {
            break;
        }
    }
    
    return maxNumber;
}

void writeFile(int maxNumber) {
    FILE *fp;
    fp = fopen("maxNumber.txt","w+");
    fprintf(fp,"%d", maxNumber);
    fclose(fp);
}


