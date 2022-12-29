/**
 * @file heap.c
 *
 * @author Caleb Krcil
 *
 * @date 4/11/2022
 *
 * Assignment: Homework 4
 *
 * @brief a program that uses heapsort to sort an array
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define LEN 4096


struct heap_t {
	int last; 		/* index of last heap element in data array */
	int size;               /* number of elements in array */
	int max; 		/* allocated size of array */
	int *data;		/* the data array */

};

enum {INIT = 1, GROW = 2};

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapsort(int arr[], int n);
void display(int arr[], int n);


int main(int argc, char **argv) 
{

	char buf[LEN];
	FILE *fp = NULL;
	int i = 0;

       	if (argc != 2) {
		printf("error in input\n");
		printf("usage: ./heap [FILE]\n");
		printf("[FILE] is a list of integers one per line\n");
		exit(EXIT_FAILURE);
	}
	else {
		fp = fopen(argv[1], "r");
		assert(fp);
	}

	struct heap_t *heap = malloc(sizeof(struct heap_t));
	heap->last = 0;
	heap->size = INIT;
	heap->max = INIT;
	heap->data = NULL;

	while (fgets(buf, LEN, fp)) {

		/* read in data from file */
		/* assign to heap->data */

		/* grow the array as necessary */
		if (heap->size > heap->max) {
			heap->data = realloc(heap->data, GROW * heap->max *sizeof(int));
			assert(heap->data);
			heap->max = GROW * heap->max;
		}
		else if (heap->data == NULL) {
			heap->data = malloc(INIT * sizeof(int));
			assert(heap->data);
		}
		*(heap->data + i) = atoi(buf); 
		heap->size++;
		i++;
	}	
		       

	/* size is off by one */
	heap->size--;


	/* todo - sort data with a heap sort */
	/* build heap */
	/* sort is in-place -- delete root and place at end of array */
	int n = heap->size;
	heapsort(heap->data, n);

	/* send data to stdin -- if you correctly built a heapsort
         * this will print the data in ascending order */
	for (i = 0; i < heap->size; i++) {
		printf("%d\n", *(heap->data + i));	
	}

	

	/* cleanup */
	free(heap->data);
	free(heap);
	fclose(fp);

	return 0;
}

/**
 * swap function, swaps the values of a and b
 * @param tmp temporary holding variable
 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * reshapes the tree into a heap structure
 * @param max the max value
 * @param leftchild the leftmost child
 * @param rightchild the rightmost child
 */
void heapify(int a[], int n, int i) {
    int max = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
  
    
    if (leftchild < n && a[leftchild] > a[max]){
      max = leftchild;
	}
    if (rightchild < n && a[rightchild] > a[max]){
      max = rightchild;
	}
    if (max != i) {
      swap(&a[i], &a[max]);
      heapify(a, n, max);
    }
}

/**
 * performs the heapsort using swap and heapify.
 */
void heapsort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
      heapify(a, n, i);
	}
    for (int i = n - 1; i >= 0; i--) {
      swap(&a[0], &a[i]); 
  
      heapify(a, i, 0);
	}
}
