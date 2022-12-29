/**
 * @file lab5_q4.c
 *
 * @author Caleb Krcil
 *
 * @date 10/10/2021
 *
 * Assignment: Lab 5
 *
 * @brief finds zodiac sign based on user input
 *
 * @bugs none
 */
#include <stdio.h>
#include <stdlib.h>

enum month
{
    JAN = 1, FEB, MAR, APR, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC
};

struct date_t {
    unsigned short month;
    unsigned short day;
    unsigned short year;
};

/**
 * Main Function
 * Asks user of date as input and passes to the sign function, has a menu
 * system.
 * @param choice yes or no for continued playing.
 */
int main(void)
{
    int choice;
    void sign(unsigned short month, unsigned short day, unsigned short year);
    struct date_t date;
    printf("Please enter your birthdate in the form month/date/year, ex: 4/23/15\n");
    scanf("%hu/%hu/%hu", &date.month, &date.day, &date.year);

    sign(date.month, date.day, date.year);
    
    while (1) {
        printf("Would you like to continue and enter more dates?\n");
        printf("Type 1 to continue and 2 to quit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Please enter your birthdate in the form month/date/year, ex: 4/23/15\n");
                scanf("%hu/%hu/%hu", &date.month, &date.day, &date.year);

                sign(date.month, date.day, date.year);
            break;
            case 2:
                printf("Laters dude\n");
                exit(EXIT_SUCCESS);
            break;
            default:
                printf("I can't read your input.");
            break;
        }
    }

}

/**
 * Finds and prints the zodiac sign based of of user input date
 * (I'm not entirely sure how zodiac signs work so the dates might be a
 * little bit off but I think it's right.)
 */
void sign(unsigned short month, unsigned short day, unsigned short year) 
{
    switch (month) {
        case 1:
        if (day <= 31) {
            if (day >= 20) {
                printf("January %hu, Aquarius\n", day);
            }
            else {
                printf("January %hu, Capricorn\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 2:
        if (day <= 29) {
            if (day >= 19) {
                printf("February %hu, Pisces\n", day);
            }
            else {
                printf("February %hu, Aquarius\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 3:
        if (day <= 31) {
            if (day >= 21) {
                printf("March %hu, Aries\n", day);
            }
            else {
                printf("March %hu, Pisces\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 4:
        if (day <= 30) {
            if (day >= 20) {
                printf("April %hu, Taurus\n", day);
            }
            else {
                printf("April %hu, Aries\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 5:
        if (day <= 31) {
            if (day >= 21) {
                printf("May %hu, Gemini\n", day);
            }
            else {
                printf("May %hu, Taurus\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 6:
        if (day <= 30) {
            if (day >= 21) {
                printf("June %hu, Cancer\n", day);
            }
            else {
                printf("June %hu, Gemini\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 7:
        if (day <= 31) {
            if (day >= 23) {
                printf("July %hu, Leo\n", day);
            }
            else {
                printf("July %hu, Cancer\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 8:
        if (day <= 31) {
            if (day >= 23) {
                printf("August %hu, Virgo\n", day);
            }
            else {
                printf("August %hu, Leo\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 9:
        if (day <= 30) {
            if (day >= 23) {
                printf("September %hu, Libra\n", day);
            }
            else {
                printf("September %hu, Virgo\n", day);
            }  
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 10:
        if (day <= 31) {
            if (day >= 23) {
                printf("October %hu, Scorpio\n", day);
            }
            else {
                printf("October %hu, Libra\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 11:
        if (day <= 30) {
            if (day >= 23) {
                printf("November %hu, Sagittarius\n", day);
            }
            else {
                printf("November %hu, Scorpio\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        case 12:
        if (day <= 31) {
            if (day >= 22) {
                printf("December %hu, Capricorn\n", day);
            }
            else {
                printf("January %hu, Sagittarius\n", day);
            }
        }
        else {
            printf("Your date could not be read.\n");
        }
        break;
        default:
        printf("Your date could not be read.\n");
        break;
    }
}