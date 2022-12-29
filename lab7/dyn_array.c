/**
 * @file dyn_array.c
 *
 * @author Caleb Krcil
 *
 * @date 10/30/2021
 *
 * Assignment: Lab 7
 *
 * @brief a program that dynamically allocates an array and will find the max
 * min, average, and median of the values in the array.
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <stdlib.h>
#define size 11


int b[] = {4, 6, 2, 4, 9, 11, 14, 16, 1, 15, 3};
void print_array(int **a);
int find_max(int **a);
int find_min(int **a);
int ave_sum(int **a);
int median(int **a);

/**
 * Dynamically allocates memory for an array and calls functions that find the
 * min, max, ave, and median of the array.
 * @param i iterates through arrays
 * @param a dynamically allocated array
 * @param max max of the array
 * @param min min of the array
 * @param ave average of the values in the array
 * @param med median of the values in the array
 */
int main(void)
{
        int i = 0;
        int** a;
        a = malloc((size)*sizeof(int*));
        if ( a == NULL )
        {
                printf("Error: out of memory.\n");
                return 0;
        }

        for ( i=0; i<size; i++ )
        {
                a[i] = malloc((11+1)*sizeof(int));
                if ( a[i] == NULL )
                {
                        break;
                }
        }
        for ( i=0; i<size; i++ )
        {
                *a[i] = b[i];
        }

        print_array(a);
        int max;
        int min;
        int ave;
        int med;
        max = find_max(a);
        min = find_min(a);
        ave = ave_sum(a);
        med = median(a);
        printf("max of array=%d\n", max);
        printf("min of array=%d\n", min);
        printf("The average of the array=%d\n", ave);
        printf("The median of the array=%d\n", med);
        for ( i = 0; i < size; i++ )
        {
                free(a[i]);
        }

        free(a);
}
/**
 * Prints out the array
 * @param i iterating value
 */
void print_array(int **a)
{
	int i;

	for(i = 0; i < size; i++){
		printf("a[%d] = %d\n", i, **a);
                a++;
        }
}

/**
 * finds the max of the array
 * @param m max of the array
 * @param i temporary value for the array
 * @return the max
 */
int find_max(int **a) {
        int m;
        int i;
        m = **a;
		
        for(i = 0; i < size; i++) {
            if(**a > m) {
            	m = **a;
	        }
            a++;    
        }
	return m;
}

/**
 * finds the minimum of the array
 * @param n minimum
 * @param i temporary value for array
 * @return the minimum
 */
int find_min(int **a) {
	int n;
	int i;
	n = **a;

	for(i = 0; i < size; i++) {
		if(**a < n) {
			n = **a;
		}
                a++;
	}
	return n;
}

/**
 * finds the average of the sum of the elements
 * @param i temporary value for array
 * @param ave average of the array
 * @return the average of the array
 */
int ave_sum(int **a) {
	int i;
	int ave;
        int sum;
	sum = 0;
	for(i = 0; i < size; i++) {
		sum = sum + **a;
                a++;
	}
	ave = sum / size;
	return ave;
}

/**
 * finds the median of the array
 * @param m median of the array
 * @return the median of the array
 */
int median(int **a) {
	int m;
	if((size % 2) == 0) {
		m = ((**(a + (size / 2)) + (**(a + ((size / 2) + 1))))) / 2;
	}
	else {
		m = (**(a + ((size + 1) / 2)));
	}
	return m;
}