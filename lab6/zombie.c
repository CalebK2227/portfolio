/**
 * @file zombie.c
 *
 * @author Caleb Krcil
 *
 * @date 10/21/2021
 *
 * Assignment: Lab 6
 *
 * @brief assigns values to arrays based on user input and prints them out.
 *
 * @details Prints out user interface based on user input and then takes that
 * input and assigns it to the arrays of structs in order to keep a log of
 * zombie data, and depending on user choice can print out the stored data.
 *
 * @bug none
 * 
 * @todo Implement a check for correct time, for example hours cant go over 24
 * and minutes and seconds 60.
 */
#include <stdio.h>
#include <stdlib.h>
#include "zombie.h"

#define LEN 32

/**
 * asks the user to input a day and time and stores those values in z[]
 * @param buf array used to get user input
 * @return z[] for the specific instance accessed
 */
struct zombie input_time(struct zombie z[], int i){
    char buf[LEN];
    
    printf("Please choose which day you encountered the zombie.\n");
    printf("1) Monday\n2) Tuesday\n3) Wednesday\n4) Thursday\n");
    printf("5) Friday\n6) Saturday\n7) Sunday\n");
    fgets(buf, LEN, stdin);
    z[i].day = atoi(buf);
    printf("Enter the time the zombie was encountered.\n");
    printf("Seperate the hours, minutes, and seconds using semicolons.\n");
    fgets(buf, LEN, stdin);
    sscanf(buf, "%d:%d:%d", &z[i].hour, &z[i].min, &z[i].sec);

    return z[i];
}

/**
 * asks the user to input amount of toes and stores those values in z[]
 * also sets dead equal to Y for use in the print zombie funciton
 * @param buf array used to get user input
 * @return z[] for the specific instance accessed
 */
struct zombie input_toes(struct zombie z[], int i){
    char buf[LEN];

    printf("Please enter the number of toes the zombie has.\n");
    fgets(buf, LEN, stdin);
    z[i].toes = atoi(buf);
    z[i].dead = 'Y';

    return z[i];
}

/**
 * asks the user to input blood amount and stores those values in z[]
 * also sets dead equal to N for use in the print zombie funciton
 * @param buf array used to get user input
 * @return z[] for the specific instance accessed
 */
struct zombie input_blood(struct zombie z[], int i){
    char buf[LEN];

    printf("Please enter the amount of blood that oozed from its body after you killed it\n");
    fgets(buf, LEN, stdin);
    z[i].blood = atof(buf);
    z[i].dead = 'N';

    return z[i];
}

/**
 * Prints out data that is stored for the zombies
 * @param i temporary value used to iterate through all 5 array instances
 * @return nothing
 */
void print_zombies(struct zombie z[]){
    int i;
    for (i = 0; i < 5; i++) {
        switch (z[i].dead) {
            case 'U':
            break;
            case 'Y': 
                printf("%d. This zombie was found dead.\n", (i + 1));
                printf("This zombie had %d toes.\n", z[i].toes);
                switch (z[i].day) {
                    case 1:
                    printf("This zombie was sighted Monday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 2:
                    printf("This zombie was sighted Tuesday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 3:
                    printf("This zombie was sighted Wednesday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 4:
                    printf("This zombie was sighted Thursday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 5:
                    printf("This zombie was sighted Friday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 6:
                    printf("This zombie was sighted Saturday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 7:
                    printf("This zombie was sighted Sunday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                }
            break;
            case 'N':
                printf("%d. This zombie was found alive.\n", (i + 1));
                printf("It was drained of %f ml of blood once killed.\n", z[i].blood);
                switch (z[i].day) {
                    case 1:
                    printf("This zombie was sighted Monday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 2:
                    printf("This zombie was sighted Tuesday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 3:
                    printf("This zombie was sighted Wednesday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 4:
                    printf("This zombie was sighted Thursday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 5:
                    printf("This zombie was sighted Friday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 6:
                    printf("This zombie was sighted Saturday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                    case 7:
                    printf("This zombie was sighted Sunday at %d:%d:%d.\n", z[i].hour, z[i].min, z[i].sec);
                    break;
                }
            break;
        }
        
    }

}