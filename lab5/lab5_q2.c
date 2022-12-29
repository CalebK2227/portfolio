/**
 * @file lab5_q2.c
 *
 * @author Caleb Krcil
 *
 * @date 10/10/2021
 *
 * Assignment: Lab 5
 *
 * @brief Enumerates and prints out colors and their respective numbers
 *
 * @bugs none
 */
#include <stdio.h>

enum color
{
    RED = 18, ORANGE, YELLOW = 5, GREEN, BLUE, INDIGO = 14, VIOLET
};

int main(void)
{
    printf("RED = %d\n", RED);
    printf("ORANGE = %d\n", ORANGE);
    printf("YELLOW = %d\n", YELLOW);
    printf("GREEN = %d\n", GREEN);
    printf("BLUE = %d\n", BLUE);
    printf("INDIGO = %d\n", INDIGO);
    printf("VIOLET = %d\n", VIOLET);

    return 0;
}