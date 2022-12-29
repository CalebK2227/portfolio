/**
 * @file multiples.c
 *
 * @author Caleb Krcil
 *
 * @date 10/21/2021
 *
 * Assignment: Lab 6
 *
 * @brief Finds the sum of all numbers divisible by 5 and 3 from 0-1000.
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#define SIZE 1000

/**
 * Finds the sum of all numbers divisible by 5 and 3 from 0-1000.
 * @param a array of numbers from 1-1000
 * @param i temporary value fro iterating through the array
 * @param sum the sum of the numbers
 * @return 0
 */
int main(void) 
{
    int a[SIZE];
    int i;
    int sum;
    sum = 0;

    for(i = 0; i < SIZE; i++) {
        a[i] = i + 1;
    }
    for(i = 0; i < SIZE; i++) {
        if (a[i] % 3 == 0) {
            sum = (sum + a[i]);
        }
        else if (a[i] % 5 == 0) {
            sum = (sum + a[i]);
        }
    }
    printf("The sum is %d\n", sum);
    
    return 0;
}