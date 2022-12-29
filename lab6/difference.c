/**
 * @file difference.c
 *
 * @author Caleb Krcil
 *
 * @date 10/21/2021
 *
 * Assignment: Lab 6
 *
 * @brief Finds the difference of the sum of squares and square of the sum
 * of all the numbers from 1-100
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#define SIZE 100

/**
 * Finds the difference of the sum of squares and square of the sum
 * of all the numbers from 1-100
 * @param a array of 100 numbers
 * @param i temporarly value for iterating through a[]
 * @param ssum the sum of the numbers squared
 * @param sums the sum of each of the numbers squared
 * @param diff the difference of the two sums
 * @return 0
 */
int main(void)
{
    int a[SIZE];
    int i;
    int ssum;
    int sums;
    int diff;
    sums = 0;
    ssum = 0;

    for(i = 0; i < SIZE; i++) {
        a[i] = i + 1;
    }
    for(i = 0; i < SIZE; i++) {
        ssum = (ssum + a[i]);
    }
    ssum = ssum * ssum;
    for(i = 0; i < SIZE; i++) {
        sums = (sums + (a[i] * a[i]));
    }
    diff = ssum - sums;
    printf("The difference is %d\n", diff);

    return 0;
}