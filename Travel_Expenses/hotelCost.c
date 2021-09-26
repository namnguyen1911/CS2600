#include <stdio.h>
#include "header.h"

void hotelCost(int *total, int days){
    int dailyHotelExpense = 90;
    total[0] = days*dailyHotelExpense;

    printf("How much did you spend on lodging?");
    scanf("%d",total[1]);
}