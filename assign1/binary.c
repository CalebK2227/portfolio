/**
 * @file binary.c
 *
 * @author Caleb Krcil
 *
 * @date 1/31/2022
 *
 * Assignment: Homework 1
 *
 * @brief a program that uses binary search to find the last occurance of a 
 * number in an array.
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>


int binary(int first, int last, int middle, int array[], int target, int index, int max);

/**
 * Main function, calls the binary sort based off of the user input array.
 * @param i temporary value
 * @param first first array value
 * @param last last array value
 * @param middle middle array value
 * @param n number of array elements
 * @param target the number being searched for
 * @param index where the number was found
 * @param max value to find the last occurance of a number
 * @param place the index the target was found at.
 * @param array the array
 */
int main(void){
    int i;
    int first;
    int last;
    int middle;
    int n;
    int target;
    int index = -1;
    int max = 0;
    int place;

    printf("Enter the number of elements you want in the array.\n");
    scanf("%d", &n);
    int array[n];
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    printf("Enter %d numbers.\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    printf("Enter the number you want to search for:\n");
    scanf("%d", &target);
    place = binary(first, last, middle, array, target, index, max);
    if (place == -1){
        printf("%d is not in the list.\n", target);
    }
    else{
        printf("%d was found last at index %d.\n", target, place);
    }
    return 0;
}

/**
 * Performs the binary search algorithm.
 */
int binary(int first, int last, int middle, int array[], int target, int index, int max){
    while (first <= last) {
        if (array[middle] < target){
            first = middle + 1;
        }
        else if (array[middle] == target){
            index = middle;
            break;
        }
        else{
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last){
        return index;
    }
    while (max == 0){
        if (array[index] == array[index + 1]){
            index = index + 1;
        }
        else{
            max = 1;
        }
    }
    return index;
}