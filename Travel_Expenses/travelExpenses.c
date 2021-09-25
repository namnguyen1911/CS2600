#include <stdio.h>
#include <stdbool.h>

//Testing Testing.. Benjamin Ung
//Declaration
double totalExpense();
double allowableExpense();
double exessAmount();
double saveAmount();
int checkIntChar();
double checkDoubleChar();
bool checkChar();

//Main function
int main() {
    //Declaration and initialization
    int daysOfTrip = 0, timeOfDeparture = 0, timeOfArrival = 0, amountOfMeals = 0;
    double airfare = 0.0, carRental = 0.0, parkingFees = 0.0, taxiFees = 0.0, conferenceFees = 0.0, hotelExpenses = 0.0, miles = 0.0;
    bool privateVehicle = false;
    char carType = '\0';

    printf("Enter the total number of days spent on the trip: ");
    daysOfTrip = checkIntChar();

    printf("Enter the the time of departure on the first day of the trip: ");
    timeOfDeparture = checkIntChar();

    printf("Enter the time of arrival back home on the last day of the trip: ");
    timeOfArrival = checkIntChar();

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

    printf("Enter the hotel expenses: ");
    hotelExpenses = checkDoubleChar();

    printf("Enter the conference or registration fee: ");
    conferenceFees = checkDoubleChar();

    printf("Enter amount of meals: ");
    amountOfMeals = checkIntChar();








    return 0;
}

//Implementation
double totalExpense() {}
double allowableExpense() {}
double exessAmount() {}
double saveAmount() {}

//If users input characters instead of integer, prompt reinput and remove all buffers
int checkIntChar() {
    int number;

    while(true) {
        if((scanf("%d%*c", &number)) != 1) {
            printf("Invalid input!\n");
            while((number = getchar()) != EOF && number != '\n');
        }
        else {
            break;
        }
    }
    return number;
}

//If users input characters instead of integer, prompt reinput and remove all buffers
double checkDoubleChar() {
    double number;

    while(true) {
        if((scanf("%lf%*c", &number)) != 1) {
            printf("Invalid input!\n");
            while((number = getchar()) != EOF && number != '\n');
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



