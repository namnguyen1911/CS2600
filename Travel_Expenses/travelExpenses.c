//---------------------
//CS2600.04
//Group 08:
//Nam Nguyen
//Yvette Carlos
//Jesse Chu
//Benjamin Ung
//---------------------
#include <stdio.h>
#include <stdbool.h>
#include "header.h"

//Main function
int main() {
    //Declaration and initialization
    //time is in military time (000--700--1200--1500--2359)
    int daysOfTrip = 0, timeOfDeparture = 0, timeOfArrival = 0;
    double airfare = 0.0, carRental = 0.0, parkingFees = 0.0, taxiFees = 0.0, conferenceFees = 0.0, hotelExpenses = 0.0, miles = 0.0;
    bool privateVehicle = false;
    //{allowable, actual}
    double hotel[2];
    //create an array to pass through function, limitations of C
    double mealExpense[2];

    printf("Enter the total number of days spent on the trip: ");
    daysOfTrip = checkIntChar();
    //Check if users input less than 2 days
    while(daysOfTrip < 1) {
        printf("Should be greater than 1\n");
        daysOfTrip = checkIntChar();
    }

    
    printf("Enter the the military time of departure on the first day of the trip (7am is 700): ");
    timeOfDeparture = checkIntChar();
    //Check if users input the wrong time
    while(timeOfDeparture < 0 || timeOfDeparture > 2359) {
        printf("Invalid input!\n");
        timeOfDeparture = checkIntChar();
    }

    printf("Enter the military time of arrival back home on the last day of the trip (11pm is 2300): ");
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


    //Display
    printf("%s\n","-----------------------------------------------------------------------------------------------------------------------");
    printf("%-27s %c %20s %c %20s %c %20s %c %20s\n","Name of expenses", '|', "Allowable Amount", '|', "Actual Expenses", '|', "Reimbursement", '|', "Saving");
    printf("%s\n","-----------------------------------------------------------------------------------------------------------------------");
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Airfare", '|', airfare, '|', airfare, '|', 0.0, '|', 0.0);
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Car rentals", '|', carRental, '|', carRental, '|', 0.0,'|', 0.0);
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Miles driven expenses", '|', milesExpenses(miles), '|', milesExpenses(miles),'|', 0.0,'|',0.0);
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Taxi expenses", '|', allowableTaxiFee(daysOfTrip) , '|', taxiFees, '|', excessAmount(allowableTaxiFee(daysOfTrip),taxiFees),'|',saveAmount(allowableTaxiFee(daysOfTrip),taxiFees));
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Parking", '|', allowableParkingFee(daysOfTrip), '|', parkingFees, '|', excessAmount(allowableParkingFee(daysOfTrip),parkingFees), '|', saveAmount(allowableParkingFee(daysOfTrip),parkingFees));
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Conference or Registration", '|', conferenceFees, '|', conferenceFees,'|', 0.0,'|',0.0);
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Hotel", '|', hotel[0], '|', hotel[1],'|', excessAmount(hotel[0],hotel[1]),'|',saveAmount(hotel[0],hotel[1]));
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Meals", '|', mealExpense[0], '|', mealExpense[1],'|', excessAmount(mealExpense[0],mealExpense[1]),'|',saveAmount(mealExpense[0],mealExpense[1]));
    printf("%s\n","-----------------------------------------------------------------------------------------------------------------------");
    printf("%-27s %c %20.2lf %c %20.2lf %c %20.2lf %c %20.2lf\n","Total", '|', totalExpense(airfare,carRental,milesExpenses(miles),allowableTaxiFee(daysOfTrip),allowableParkingFee(daysOfTrip),conferenceFees,hotel[0],mealExpense[0]),
     '|', totalExpense(airfare,carRental, milesExpenses(miles),taxiFees,parkingFees,conferenceFees,hotel[1],mealExpense[1]), 
     '|', totalExpense(0.0,0.0,0.0,excessAmount(allowableTaxiFee(daysOfTrip),taxiFees),excessAmount(allowableParkingFee(daysOfTrip),parkingFees),0.0,excessAmount(hotel[0],hotel[1]),excessAmount(mealExpense[0],mealExpense[1])),
     '|', totalExpense(0.0,0.0,0.0,saveAmount(allowableTaxiFee(daysOfTrip),taxiFees),saveAmount(allowableParkingFee(daysOfTrip),parkingFees),0.0,saveAmount(hotel[0],hotel[1]),saveAmount(mealExpense[0],mealExpense[1])));





    return 0;
}

//Implementation


//If users input characters instead of integer, prompt reinput and remove all buffers
int checkIntChar() {
    int number = 0, buffer = 0;

    while(true) {
        if((scanf("%d%*c", &number)) != 1) {
            printf("Invalid input!\n");
            while((number = getchar()) != EOF && number != '\n');
        }
        else if(number < 0 || number == 0) {
            printf("Invalid input!\n");
            //clear buffer
            while((number = getchar()) != EOF && number != '\n');
        }
        else {
            break;
        }
    }
    //Clear buffer
    while((buffer = getchar()) != EOF && buffer != '\n');
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

double milesExpenses(double miles) {
    return 0.27 * miles;
}

