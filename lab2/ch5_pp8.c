/**
 * @file ch5_pp8.c
 *
 * @author Caleb Krcil
 *
 * @date 9/14/2021
 *
 * Assignment: Lab 2
 *
 * @brief A program that determines closest flight departure time.
 *
 * @details A program that takes user input in the form of 24 hour time and
 * translates that time into minutes since midnight and then determines which 
 * of the departure times the time entered is closest to and prints the result
 * to the user.
 *
 * @bug none
 *
 * @todo none
 */

#include <stdio.h>

/**
 * Main function
 * Takes user input as 24 hour time and translates it into minutes since
 * midnight and then calculates which departure time is closest to the 
 * input time.
 * @param h hours
 * @param m minutes
 * @param time time in minutes since midnight
 * @return 0
 */
int main(void) {

    int h;
    int m;

    printf("Welcome to the Imaginary Airport flight suggestion interface.\n");
    printf("Please enter a time in the format: hours:minutes using the 24 hour clock.\n");
    scanf("%d:%d", &h , &m);
    int time = (h * 60 + m);

    if (0 <= time  && time < 480)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if (480 <= time && time < 583)
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if (583 <= time && time < 679)
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if (679 <= time && time < 767)
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    else if (767 <= time && time < 840)
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if (840 <= time && time < 945)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if (945 <= time && time < 1140)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else if (1140 <= time && time < 1305)
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    else if (1305 <= time && time < 1439)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else
        printf("Your time could not be read. Please try again.\n");
    
    
    return 0;
}