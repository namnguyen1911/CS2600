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
double excessAmount(double allowable, double actual);
double saveAmount(double allowable, double actual);
double milesExpenses(double miles);
//double calcCostOfEmployeeParkingFees(int daysOfTrip, int fees);
//double calcCostOfCompanyParkingFees(int daysOfTrip, int fees);
//double calcCostOfEmployeeTaxiFees(int daysOfTrip, int fees);
//double calcCostOfCompanyTaxiFees(int daysOfTrip, int fees);
double allowableTaxiFee(int daysOfTrip);
double allowableParkingFee(int daysOfTrip);
#endif //header.h
