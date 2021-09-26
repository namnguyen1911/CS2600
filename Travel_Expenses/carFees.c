#include <stdio.h>
#include "header.h"

double calcCostOfEmployeeParkingFees (int daysOfTrip, int fees){
    fees -= (daysOfTrip * 6.00);
    if (fees <= 0){
        return 0.0;
    }
    else {
        return fees;
    }
}

double calcCostOfCompanyParkingFees (int daysOfTrip, int fees){
    if (fees < daysOfTrip * 6.00){
        return fees;
    }
    else {
        return daysOfTrip * 6.00;
    }
}

double calcCostOfEmployeeTaxiFees (int daysOfTrip, int fees){
    fees -= (daysOfTrip * 10.00);
    if (fees <= 0){
        return 0.0;
    }
    else {
        return fees;
    }
}

double calcCostOfCompanyParkingFees (int daysOfTrip, int fees){
    if (fees < daysOfTrip * 10.00){
        return fees;
    }
    else {
        return daysOfTrip * 10.00;
    }
}
