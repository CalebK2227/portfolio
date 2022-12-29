/**
 * @file ch5_pp11.c
 *
 * @author Caleb Krcil
 *
 * @date 9/14/2021
 *
 * Assignment: Lab 2
 *
 * @brief A program that takes a two digit number and prints out its english
 * word.
 *
 * @details A program that takes user input in the form of a two digit number
 * and splits the first and second digits in order to determine what the 
 * english word for that number is.
 * 
 *
 * @bug none
 *
 * @todo none
 */

#include <stdio.h>

int first;
int numb;
int second;

/**
 * Main function
 * Takes user input in the form of a two digit number and then prints
 * the numbers english word back to the user.
 * @param numb the number that the user input
 * @param first first digit of the number
 * @param second second digit of the number
 * @return zero
 */
int main(void) {
    printf("Enter a two-digit number:\n");
    scanf("%d", &numb);
    int second = (numb % 10);
    int first = (numb / 10);

    switch(numb) {
    case 11:
        printf("eleven\n");
    break;
    case 12:
        printf("twelve\n");
    break;
    case 13:
        printf("thirteen\n");
    break;
    case 14:
        printf("fourteen\n");
    break;
    case 15:
        printf("fifteen\n");
    break;
    case 16:
        printf("sixteen\n");
    break;
    case 17:
        printf("seventeen\n");
    break;
    case 18:
        printf("eighteen\n");
    break;
    case 19:
        printf("nineteen\n");
    break;
    default:
        switch(first) {
        case 1:
            printf("ten");
        break;
        case 2:
            printf("twenty");
        break;
        case 3:
            printf("thirty");
        break;
        case 4:
            printf("forty");
        break;
        case 5:
            printf("fifty");
        break;
        case 6:
            printf("sixty");
        break;
        case 7:
            printf("seventy");
        break;
        case 8:
            printf("eighty");
        break;
        case 9:
            printf("ninety");
        break;
        default:
            printf("Your number is not recognized\n");

        }

        switch(second) {
        case 1:
            printf("-one\n");
        break;
        case 2:
            printf("-two\n");
        break;
        case 3:
            printf("-three\n");
        break;
        case 4:
            printf("-four\n");
        break;
        case 5:
            printf("-five\n");
       break;
        case 6:
            printf("-six\n");
        break;
        case 7:
            printf("-seven\n");
        break;
        case 8:
            printf("-eight\n");
        break;
        case 9:
            printf("-nine\n");
        break;
        case 0:
            printf(".\n");
        break;
        default:
            printf("Your number is not recognized.\n");
        }
    }
   return 0;
}