/**
 * @file array_struct.c
 *
 * @author Caleb Krcil
 *
 * @date 10/10/2021
 *
 * Assignment: Lab 5
 *
 * @brief Performs calculations based on structs of arrays.
 *
 * @details Initializes the array and then performs calculations based on the
 * values stored, which are the max, min, and average of the age and height.
 *
 * @bugs none
 */

#include "array_struct.h"
#include <stdio.h>

/**
 * Main Function
 * @param amin minimum age
 * @param hmin minimum height
 * @param amax max age
 * @param hmax max height
 * @param avea avergage age
 * @param aveh average height
 */
int main(void)
{

	struct data_t data[SIZE];

	/* data initialization calls */
	init_array(data, 0, 'A', 23, 74);
	print_one((data)[0]);
	init_array(data, 1, 'B', 22, 64);
	init_array(data, 2, 'C', 19, 68);
	init_array(data, 3, 'D', 20, 76);
	init_array(data, 4, 'E', 22, 62);
	
	int amin = min_age(data);
	int hmin = min_height(data);
	int amax = max_age(data);
	int hmax = max_height(data);
	int avea = ave_age(data);
	int aveh = ave_height(data);

	printf("Index of min age - %d\n", amin);
	printf("Index of min height - %d\n", hmin);
	printf("Index of max age - %d\n", amax);
	printf("Index of max height - %d\n", hmax);
	printf("Average age - %d\n", avea);
	printf("Average height - %d\n", aveh);

	return 0;
}
/**
 * prints out the elements of one array
 */
void print_one(struct data_t data) {
	printf("Subject-%c\t", data.subject);
	printf("Age-%d\t", data.age);
	printf("Height-%d\n", data.height);
}

/**
 * initializes the arrays for each index
 */
void init_array(struct data_t data[], int index, char id, int years, int inches)
{
	(data)[index].subject = id;
	(data)[index].age = years;
	(data)[index].height = inches;
}

/**
 * finds the minimum age
 * @param i temporary value for array
 * @param m minimum age
 * @param index index of the minimum age
 * @return index
 */
int min_age(struct data_t data[]) {
	int i;
	int m;
	int index;
	m = data[0].age;
	index = 0;
	
	for(i = 1; i < SIZE; i++) {
		if(data[i].age < m) {
			m = data[i].age;
			index = i;
		}
	}
	return index;
}

/**
 * finds the minimum height
 * @param i temporary value for array
 * @param m minimum height
 * @param index index of the minimum height
 * @return index
 */
int min_height(struct data_t data[]) {
	int i;
	int m;
	int index;
	m = data[0].height;
	index = 0;

	for(i = 1; i < SIZE; i++) {
		if(data[i].height < m) {
			m = data[i].height;
			index = i;
		}
	}
	return index;
}

/**
 * finds the maximum age
 * @param i temporary value for array
 * @param m maximum age
 * @param index index of the maximum age
 * @return index
 */
int max_age(struct data_t data[]) {
	int i;
	int m;
	int index;
	m = data[0].age;
	index = 0;

	for(i = 1; i < SIZE; i++) {
        if(data[i].age > m) {
        	m = data[i].age;
			index = i;
		}
    }
	return index;
}

/**
 * finds the maximum height
 * @param i temporary value for array
 * @param m maximum height
 * @param index index of the maximum height
 * @return index
 */
int max_height(struct data_t data[]) {
	int i;
	int m;
	int index;
	m = data[0].height;
	index = 0;

	for(i = 1; i < SIZE; i++) {
        if(data[i].height > m) {
        	m = data[i].height;
			index = i;
		}
    }
	return index;
}

/**
 * Finds the average age
 * @param i temporary value for the array
 * @param sum sum of all the ages
 * @param ave average of the ages
 * @return ave
 */
int ave_age(struct data_t data[]) {
	int i;
	int sum;
	int ave;
	sum = 0;
	for(i = 0; i < SIZE; i++) {
		sum = sum + data[i].age;
	}

	ave = sum / SIZE;

	return ave;
}

/**
 * Finds the average height
 * @param i temporary value for the array
 * @param sum sum of all the heights
 * @param ave average of the heights
 * @return ave
 */
int ave_height(struct data_t data[]) {
	int i;
	int sum;
	int ave;
	sum = 0;
	for(i = 0; i < SIZE; i++) {
		sum = sum + data[i].height;
	}

	ave = sum / SIZE;

	return ave;
}

