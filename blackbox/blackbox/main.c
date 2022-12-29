/**
 * @file main.c
 *
 * @author Caleb Krcil
 *
 * @date 4/25/2022
 *
 * Assignment: blackbox
 *
 * @brief a program that tests functions and prints out how long 
 * it took for each funciton to run.
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "blackbox.h"

#define BUFSIZE 1000

void shuffle(unsigned long list[], int n);
void reverse(unsigned long list[], int n); 
unsigned long random_number(void);

/**
 * Main function, takes user input for list length and calls each 
 * function to be tested based on that value. Then determines how long
 * the function ran for.
 * @param time1 holds the time it took for a function to run in computer ticks
 * @param time2 holds the time it took for a function to run in computer ticks
 * @param time3 holds the time it took for a function to run in computer ticks
 * @param sec1 holds the time it took for a function to run in seconds
 * @param sec2 holds the time it took for a function to run in seconds
 * @param sec3 holds the time it took for a function to run in seconds
 * @param avetime the average of the tick times
 * @param avesec the average of the second times
 * @param msec holds the time it took for a function to run in seconds
 * @param time_elapsed holds how long it took for the function to run
 * @param n user input list size
 * @param i iterating value
 * @param size list size
 * @param choice user input choice for list size and function run etc
 * @param list array of input size n
 */
int main()
{
    unsigned long i;
    int time1;
    int time2;
    int time3;
    int sec1;
    int sec2;
    int sec3;
    int avetime;
    int avesec;
    int msec;
    clock_t time_elapsed;
    unsigned long n;
    int size;
    int choice;
    time_elapsed = clock();
    printf("Enter the size you want the list to be\n");
    scanf("%d", &size);
    n = (unsigned long) size;
    unsigned long list[size];

    for(i = 0; i < size; i++){
        list[i] = i;
    }

    printf("Do you want an in order (1), reverse order (2), or shuffled array (3)?\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
        break;
        case 2:
        reverse(list, n);
        break;
        case 3:
        shuffle(list, n);
        break;
    }

    printf("Which of the functions do you want to test 1,2,3,4,5,6, or 7?\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
        function_1(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time1 = (int) time_elapsed;
        sec1 = msec;
        function_1(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time2 = (int) time_elapsed;
        sec2 = msec;
        function_1(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time3 = (int) time_elapsed;
        sec3 = msec;
        avetime = (time1 + time2 + time3) / 3;
        avesec = (sec1 + sec2 + sec3) / 3;
        printf("1) Time taken: %d.%03d seconds\n", avesec/1000, avesec%1000);
        printf("1) CPU time elapsed: %d ticks\n", avetime);
        break;
        case 2:
        function_2(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time1 = (int) time_elapsed;
        sec1 = msec;
        function_2(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time2 = (int) time_elapsed;
        sec2 = msec;
        function_2(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time3 = (int) time_elapsed;
        sec3 = msec;
        avetime = (time1 + time2 + time3) / 3;
        avesec = (sec1 + sec2 + sec3) / 3;
        printf("2) Time taken: %d.%03d seconds\n", avesec/1000, avesec%1000);
        printf("2) CPU time elapsed: %d ticks\n", avetime);
        break;
        case 3:
        function_3(list, n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time1 = (int) time_elapsed;
        sec1 = msec;
        function_3(list, n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time2 = (int) time_elapsed;
        sec2 = msec;
        function_3(list, n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time3 = (int) time_elapsed;
        sec3 = msec;
        avetime = (time1 + time2 + time3) / 3;
        avesec = (sec1 + sec2 + sec3) / 3;
        printf("3) Time taken: %d.%03d seconds\n", avesec/1000, avesec%1000);
        printf("3) CPU time elapsed: %d ticks\n", avetime);
        break;
        case 4:
        function_4(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time1 = (int) time_elapsed;
        sec1 = msec;
        function_4(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time2 = (int) time_elapsed;
        sec2 = msec;
        function_4(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time3 = (int) time_elapsed;
        sec3 = msec;
        avetime = (time1 + time2 + time3) / 3;
        avesec = (sec1 + sec2 + sec3) / 3;
        printf("4) Time taken: %d.%03d seconds\n", avesec/1000, avesec%1000);
        printf("4) CPU time elapsed: %d ticks\n", avetime);
        break;
        case 5:
        function_5(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time1 = (int) time_elapsed;
        sec1 = msec;
        function_5(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time2 = (int) time_elapsed;
        sec2 = msec;
        function_5(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time3 = (int) time_elapsed;
        sec3 = msec;
        avetime = (time1 + time2 + time3) / 3;
        avesec = (sec1 + sec2 + sec3) / 3;
        printf("5) Time taken: %d.%03d seconds\n", avesec/1000, avesec%1000);
        printf("5) CPU time elapsed: %d ticks\n", avetime);
        break;
        case 6:
        function_6(list, n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time1 = (int) time_elapsed;
        sec1 = msec;
        function_6(list, n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time2 = (int) time_elapsed;
        sec2 = msec;
        function_6(list, n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time3 = (int) time_elapsed;
        sec3 = msec;
        avetime = (time1 + time2 + time3) / 3;
        avesec = (sec1 + sec2 + sec3) / 3;
        printf("6) Time taken: %d.%03d seconds\n", avesec/1000, avesec%1000);
        printf("6) CPU time elapsed: %d ticks\n", avetime);
        break;
        case 7:
        function_7(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time1 = (int) time_elapsed;
        sec1 = msec;
        function_7(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time2 = (int) time_elapsed;
        sec2 = msec;
        function_7(n);
        time_elapsed = clock() - time_elapsed;
        msec = time_elapsed * 1000 / CLOCKS_PER_SEC;
        time3 = (int) time_elapsed;
        sec3 = msec;
        avetime = (time1 + time2 + time3) / 3;
        avesec = (sec1 + sec2 + sec3) / 3;
        printf("7) Time taken: %d.%03d seconds\n", avesec/1000, avesec%1000);
        printf("7) CPU time elapsed: %d ticks\n", avetime);
        break;
    }
    return 0;
}

/**
 * Generates a random number
 * @param n random number generated
 * @param p limiting valule
 * @param r random number
 * @param i iterating value
 */
unsigned long random_number(void){
    unsigned long n, p, r;
    int i;

    n = 0;
    for(i = 0, p = 1; i < 8; i++, p *= 256){
        r = random() % 256;
        n += r * p;
    }
    return n;
}

/**
 * Shuffles the list
 * @param i iterating value
 * @param j temporary value
 * @param t temporary value
 */
void shuffle(unsigned long list[], int n){
    int i;
    int j;
    int t;
    if (n > 1){
        for(i = 0; i < n - 1; i++){
            j = random_number() % (i + 1);
            t = list[j];
            list[j] = list[i];
            list[i] = t;
        }
    }
}

/**
 * Reverses the list
 * @param a temporary array
 * @param i iterating value
 */
void reverse(unsigned long list[], int n){
    unsigned long a[n];
    int i;
    
    for(i = 0; i < n; i++){
        a[n - 1 - i] = list[i];
    }
    for(i = 0; i < n; i++){
        list[i] = a[i];
    }
}
