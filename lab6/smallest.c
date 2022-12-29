/**
 * @file smallest.c
 *
 * @author Caleb Krcil
 *
 * @date 10/21/2021
 *
 * Assignment: Lab 6
 *
 * @brief finds the smallest number divisible by all numbers 1-20
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>

/**
 * finds the smallest number divisible by all numbers 1-20
 * @param i number that is checked to and added to until its divisible by 1-20
 * @return 0
 */
int main(void)
{
    unsigned long i;
    i = 2520;
    
    while (((i % 11) + (i % 12) + (i % 13) + (i % 14) + (i % 15) + (i % 16) + (i % 17) + (i % 18) + (i % 19) + (i % 20) != 0))
    {
        i = i + 2520;
    }
    
        
    printf("Smallest is %lu\n", i);
return 0;
}
