/**
 * @file lab6.c
 *
 * @author Caleb Krcil
 *
 * @date 10/21/2021
 *
 * Assignment: Lab 6
 *
 * @brief Calls functions from zombie.c based on user input and is the main
 * menu system for the program.
 *
 * @details Creates a menu system that will call functions from zombie.c based
 * on what the user inputs and will end the program only when the user is
 * finished inputting information on the zombies.
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <stdlib.h>
#include "zombie.h"
#define LEN 32
#define len 5

/**
 * Main user interface and menu, calls functions from zombie.c based on user
 * input
 * @param z array that has all the data for the zombies
 * @param buf array that holds user input
 * @param choice the initial choice the user inputs
 * @param dead holds the case for the zombie being dead or alive
 * @param i temporary value for iterating through a
 * @return 0
 */
int main(void)
{
    struct zombie z[len];
    char buf[LEN];
    int choice;
    char dead;
    int i;
    i = 0;
    for (i = 0; i < 5; i++) {
        z[i].dead = 'U';
    }
    while (1) {
        printf("Enter your choice\n");
        printf("1) Enter new zombie information\n");
        printf("2) Display zombie information\n");
        printf("3) Return to fighting zombies (exit)\n");
        fgets(buf, LEN, stdin);
        choice = atoi(buf);

        switch (choice) {
            case 1:
                printf("Was the zombie found dead? Y or N\n");
                fgets(buf, LEN, stdin);
                dead = buf[0];
                if ((i % 5) == 0) {
                    i = 0;
                }
                switch (dead) {
                    case 'Y':
                        input_toes(z, i);
                        input_time(z, i);
                        i++;
                    break;
                    case 'N':
                        input_blood(z, i);
                        input_time(z, i);
                        i++;
                    break;
                    default:
                        printf("I cannot read your input.\n");
                    break;
                }
            break;
            case 2:
                print_zombies(z);
            break;
            case 3:
                printf("Good luck, try not to die\n");
                exit(EXIT_SUCCESS);
            break;
            default:
                printf("I can't read your input.\n");
            break;
        }
    }
    return 0;
}