#ifndef header_h 
//if multiple files have include header it will only be read once by compiler
#define header_h

#include <stdbool.h>
#include <stdio.h>

int checkIntChar();
double checkDoubleChar();
bool checkChar();
void hotelCost(int *total, int days);

void mealPlan(int *total, int days, int departureTime, int arrivalTime);
#endif //header.h