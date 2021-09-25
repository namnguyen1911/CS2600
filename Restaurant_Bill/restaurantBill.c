#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//The prices of the meals
const double SALAD = 9.95;
const double SOUP = 4.55;
const double SANDWICH = 13.25;
const double PIZZA = 22.35; 

double calculateTax(double tax, double meal);
double calculateTip(double tip, double meal);

int main() {
    time_t t;

    //Creates variables and initializes
    double tax = 0.0;
    double tip = 0.0;
    double mealPrice = 0.0;
    int number = 0;

    //Prompt the users to enter tax and tip as percentage
    printf("Enter tax and tip (8.75 10): ");
    scanf("%lf %lf", &tax, &tip);

    //Randomly choose 4 numbers from 0 to 3
    srand((unsigned) time(&t));
    number = rand() % 4;

    //Output the name of the meal and its price
    if(number == 0) {
        printf("Your salad costs %.2f$\n", SALAD);
        mealPrice = SALAD;
    }
    else if (number == 1) {
        printf("Your soup costs %.2f$\n", SOUP);
        mealPrice = SOUP;
    }
    else if (number == 2) {
        printf("Your sandwich costs %.2f$\n", SANDWICH);
        mealPrice = SANDWICH;
    }
    else {
        printf("Your pizza costs %.2f$\n", PIZZA);
        mealPrice = PIZZA;
    }

    //Calculate the tax and output it
    printf("Your tax is %.2f$\n", calculateTax(tax,mealPrice));

    //Calculate the tip and output it
    printf("Your tip is %.2f$\n", calculateTax(tip,mealPrice));

    //Calculate the total cost and output it
    printf("Your total meal is %.2f$\n", mealPrice + calculateTax(tax,mealPrice) + calculateTax(tip,mealPrice));

    return 0;
}

double calculateTax(double tax, double meal) {
    return meal * (tax / 100.0);
}

double calculateTip(double tip, double meal) {
    return meal * (tip / 100.0);
}