/**
 * @file sundays.c
 *
 * @author Caleb Krcil
 *
 * @date 10/21/2021
 *
 * Assignment: Lab 6
 *
 * @brief finds the amount of times sunday was the first day of the month in
 * the 20th century
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>

/**
 * finds the number of sundays that were the first of the month from 1901-2000
 * @param days array that holds the number of days in each month
 * @param Sundays the amount of sundays that meet the condition
 * @param i temporary value for iterating through the array
 * @param year what year it is checking
 * @param day the starting day of the month
 * @return 0
 */
int main(void)
{
    int days[] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Sundays;
    Sundays = 0;
    int i;
    int year;
    year = 1901;
    int day;
    day = 3;
    for (year = 1901; year < 2001; year++) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            days[1] = 29;
        }

        else {
            days[1] = 28;
        }
    
        for (i = 0; i < 12; i++){
            if (days[i] == 31){
                day = day + 3;
                if (day > 7){
                    day = day - 7;
                }
            }
            if (days[i] == 28){
                day = day + 0;
            }
            if (days[i] == 30){
                day = day + 2;
                if (day > 7){
                    day = day - 7;
                }
            }
            if (days[i] == 29){
                day = day + 1;
                if (day > 7){
                    day = day - 7;
                }
            }
            if (day == 1){
                Sundays = Sundays + 1;
            }
        }
    }
    printf("There are %d sundays on the first of the month\n", Sundays);
    return 0;
}