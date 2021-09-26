#include <stdio.h>
#include "header.h"

double allowableExpense(int expenseAllowed){
    int hotelExpense = 90.00;
    int parkingFees = 6.00;
    int taxiFees = 10.00;
    int breakfast = 9.00;
    int lunch = 12.00;
    int dinner = 16.00;

    expenseAllowed = hotelExpense + parkingFees + taxiFees + breakfast + lunch + dinner;
    return 0;
}