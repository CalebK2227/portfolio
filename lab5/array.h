/**
 * @file array.h
 * 
 * @author Caleb Krcil
 *
 * @date 9/23/2021
 *  
 * Assignment: Lab 3 
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *  
 * @bugs none
 *
 * @todo add floating point versions of the functions
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h> 		/* for size_t declaration */

/* function declarations go here */
void print_array(int a[], size_t size);
int find_max(int *a, size_t size);
int find_min(int *a, size_t size);
int midpoint(int max, int min);
int get_count(int a[], size_t size, int type, int x);
int linear_search(int a[], size_t size, int m);
int sum_element(int a[], size_t size);
int ave_sum(int a[], size_t size, int sum);
int reverse(int a[], size_t size);
int median(int a[], size_t size);
int even_count(int a[], size_t size);
int odd_count(int a[], size_t size);
int divisible_count(int a[], size_t, int div);
#endif
