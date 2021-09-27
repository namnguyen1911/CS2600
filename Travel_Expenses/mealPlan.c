

/*This program is meant to calcuate:
     how many meals are eaten
     how much money did they cost
     how much of that is paid for by the company

Instructions:
On the first day of the trip, breakfast is allowed as an expense if the time of departure is before 7 a.m. 
Lunch is allowed if the time of departure is before 12 noon. 
Dinner is allowed on the first day if the time of departure is before 6 p.m. 
On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m. 
Lunch is allowed if the time of arrival is after 1 p.m. 
Dinner is allowed on the last day if the time of arrival is after 7 p.m. 

The program should only ask for the amounts of allowable meals. (The company allows up to $9 for breakfast, $12 for lunch, and $16 for dinner. Anything more than this must be paid by the 
 */
#include <stdio.h>
#include "header.h"

void mealPlan(double *total, int days, int departureTime, int arrivalTime){
    //total {allowable expense, expense}
    //price of breakfast, lunch, and dinner respectively
    int breakfast = 9;
    int lunch = 12;
    int dinner = 16;

    //departure time meals allowed
    if(departureTime < 700){
        total[0] = total[0] + breakfast + lunch + dinner;
    }else if(departureTime < 1200){
        total[0] = total[0] + lunch + dinner;
    }else if(departureTime < 1800){
        total[0] = total[0] + dinner;
    }

    if(days > 1){
        //arrival time meals allowed
        if(arrivalTime > 1900){
            total[0] = total[0] + breakfast + lunch + dinner;
        }else if(arrivalTime > 1300){
            total[0] = total[0] + breakfast + lunch;
        }else if(arrivalTime > 800){
            total[0] = total[0] + breakfast;
        }
    }
    //if there are days other than arrival day and leaving day
    if(days > 2){
        total[0] = total[0] + (days-2)*(breakfast + lunch + dinner);
    }
    
    printf("How much did you actually spend on meals? ");
    //scanf("%d", total[1]);
    total[1] = checkDoubleChar();
}