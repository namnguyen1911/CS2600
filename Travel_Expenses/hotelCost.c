#include <stdio.h>
#include "header.h"

void hotelCost(double *total, int days){
    double dailyHotelExpense = 90.0;
    total[0] = days*dailyHotelExpense;

    printf("How much did you spend on lodging? ");
    //scanf("%d",total[1]);
    total[1] = checkDoubleChar();
}