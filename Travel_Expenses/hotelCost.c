#include <stdio.h>

void hotelCost(int *total, int days){
    int dailyHotelExpense = 90;
    int total[0] = days*dailyHotelExpense;

    printf("How much did you spend on lodging?");
    scanf("%d",total[1]);
}