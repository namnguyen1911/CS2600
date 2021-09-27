#include <stdio.h>
#include "header.h"

double totalExpense(double airfare, double carRentals, double milesExpenses , double taxiFees, double parkingFees, double conferenceFees, double hotelExpenses, double mealsExpenses) {
    return airfare + carRentals + milesExpenses + taxiFees + parkingFees + conferenceFees + hotelExpenses + mealsExpenses;
}

