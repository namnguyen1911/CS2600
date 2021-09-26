
#include <stdio.h>
#include <stdbool.h>
#include "header.h"
//Testing Testing.. Benjamin Ung
//Declaration
double totalExpense();
double allowableExpense();
double excessAmount();
double saveAmount();


//Main function
int main() {
    //Declaration and initialization
    //time is in military time (000--700--1200--1500--2359)
    int daysOfTrip = 0, timeOfDeparture = 0, timeOfArrival = 0, amountOfMeals = 0;
    double airfare = 0.0, carRental = 0.0, parkingFees = 0.0, taxiFees = 0.0, conferenceFees = 0.0, hotelExpenses = 0.0, miles = 0.0;
    bool privateVehicle = false;
    //{allowable, actual}
    int hotel[2];
    //create an array to pass through function, limitations of C
    int mealExpense[2];

    printf("Enter the total number of days spent on the trip: ");
    daysOfTrip = checkIntChar();

    
    printf("Enter the the military time of departure on the first day of the trip: ");
    timeOfDeparture = checkIntChar();
    //Check if users input the wrong time
    while(timeOfDeparture < 0 || timeOfDeparture > 2359) {
        printf("Invalid input!\n");
        timeOfDeparture = checkIntChar();
    }

    printf("Enter the military time of arrival back home on the last day of the trip: ");
    timeOfArrival = checkIntChar();
    //Check if users input the wrong time
    while(timeOfArrival < 0 || timeOfArrival > 2359) {
        printf("Invalid input!\n");
        timeOfArrival = checkIntChar();
    }

    printf("Enter round-trip airfare: ");
    airfare = checkDoubleChar();

    printf("Enter car rentals: ");
    carRental = checkDoubleChar();


    printf("Did you use private car? (y/n) ");
    privateVehicle = checkChar();

    if(privateVehicle == true) {
        printf("Enter miles driven: ");
        miles = checkDoubleChar();
    }

    printf("Enter the parking fees: ");
    parkingFees = checkDoubleChar();

    printf("Enter the taxi fees: ");
    taxiFees = checkDoubleChar();

    printf("Enter the conference or registration fee: ");
    conferenceFees = checkDoubleChar();



    //Calculate total hotel cost
    hotelCost(hotel, daysOfTrip);    
   
    

    //returns {allowable expense, actual expense}
    mealPlan(mealExpense, daysOfTrip,timeOfDeparture, timeOfArrival);
    int mealDiff = mealExpense[1] - mealExpense[0];


    //Display
    printf("%-25s %c %20s %c %20s %c %20s\n","Name of expenses", '|', "Allowable Amount", '|', "Total Expenses", '|', "Reimbursement");
    printf("%s\n","----------------------------------------------------------------------------------------------");
    printf("%-25s %c %20.2lf %c %20.2lf %c %20.2lf\n","Airfare", '|', airfare, '|', airfare, '|', 0.00);
    printf("%-25s %c %20.2lf %c %20.2lf %c %20.2lf\n","Car rentals", '|', carRental, '|', carRental, '|', 0.00);
    printf("%-25s %c %20.2lf %c %20.2lf %c %20.2lf\n","Miles driven expenses", '|', 0.27*miles, '|', 0.27*miles, '|', 0.00);
    printf("%-25s %c %20.2lf %c %20.2lf %c %20.2lf\n","Taxi expenses", '|', taxiFees, '|', taxiFees, '|', taxiFees - taxiFees);





    return 0;
}

//Implementation
double totalExpense() {
    return airfare + 0.27*miles + parkingFees + taxiFees + conferenceFees;
}
double allowableExpense() {

}
double excessAmount() {
    return calcCostOfEmployeeParkingFees(daysOfTrip, parkingFees) + calcCostOfEmployeeTaxiFees(daysOfTrip, taxiFees);
}
double saveAmount() {
    return calcCostOFCompanyParkingFees(daysOfTrip, parkingFees) + calcCostOfCompanyTaxiFees(daysOfTrip, taxiFees;
}

//If users input characters instead of integer, prompt reinput and remove all buffers
int checkIntChar() {
    int number;

    while(true) {
        if((scanf("%d%*c", &number)) != 1) {
            printf("Invalid input!\n");
            while((number = getchar()) != EOF && number != '\n');
        }
        else if(number < 0) {
            printf("Cannot be negative!\n");
        }
        else {
            break;
        }
    }
    return number;
}

//If users input characters instead of double, prompt reinput and remove all buffers
double checkDoubleChar() {
    double number;

    while(true) {
        if((scanf("%lf%*c", &number)) != 1) {
            printf("Invalid input!\n");
            while((number = getchar()) != EOF && number != '\n');
        }
        else if(number < 0.0) {
            printf("Cannot be negative!\n");
        }
        else {
            break;
        }
    }
    return number;
}

bool checkChar() {
    int number = 0;

    //Clear the buffer if the inputs are wrong
    while(true) {
        number = getchar();
        if(number == 'y' || number == 'Y') {
            return true;
        }
        else if(number == 'n' || number == 'N') {
            return false;
        }
    }
}



