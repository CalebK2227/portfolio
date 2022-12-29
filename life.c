/**
 * @file life.c
 *
 * @author Caleb Krcil
 *
 * @date 11/27/2021
 *
 * Assignment: Lab 10/ GOL
 *
 * @brief a filfe that contains the functions used for the game of life 
 * processes and calculations.
 * 
 * @details contains functions that initialize the two matrices, determine 
 * the state of generations basedoff the previous ones, depending on the
 * edgetype, hedge, torus or klien, and the starting configuration. 
 * 
 * @bug when initializing the grid it doesnt wrap around correctly and seg faults
 * if the grid isnt large enough, only an issue on the larger patterns
 * 
 * @todo none
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "life.h"
#define size 256

/**
 * Initializes a matrix of width rows and height columns and sets values to 0
 * @param widthinc width incrementer
 * @param heightinc height incrementer
 * @param newmatrix temporary value used for allocating a new matrix
 * @return newmatrix
 */
unsigned char **init_matrix(int width, int height)
{
    int widthinc;
    int heightinc;
    unsigned char **newmatrix = NULL;
    newmatrix = (unsigned char**)malloc(width * sizeof(unsigned char*));
    if ( newmatrix == NULL )
    {
        printf("Error: out of memory.\n");
        return 0;
    }
    for(widthinc = 0; widthinc < width; widthinc++){
        *(newmatrix + widthinc) = (unsigned char*)malloc(height * sizeof(unsigned char));
    }
    for(widthinc = 0; widthinc < width; widthinc++){
        for(heightinc = 0; heightinc < height; heightinc++){
            *(*(newmatrix + widthinc) + heightinc) = 0;
        }
    }
    return newmatrix;
}

/**
 * Creates the starting configuration for the game to be run with
 * @param title integer used so that the program does not read in the title line.
 * @param x the starting x coordinate.
 * @param y the starting y coordinate.
 * @param buf character array that holds the current line of the file
 * @param start the file being read
 * @return matrix1
 */
unsigned char **fileset(unsigned char **matrix1, char* file, int mwidth, int mheight, int originx, int originy, int edgetype)
{
    int title = 0;
    int x;
    int y;
    char buf[size];
    FILE *start = NULL;
    if(file != NULL){
        start = fopen(file, "r");
    }
    while(fgets(buf, size, start)){
        if(title != 0){
            sscanf(buf, "%d %d", &x, &y);
            if(edgetype == 2 || edgetype == 3){
                if((originx + x) >= mheight){
                    matrix1[originy + y][originx + (mheight - x)] = 1;
                }
                else if((originy + y) >= mwidth){
                    matrix1[originy + (mwidth - y)][originx + x] = 1;
                }
                else if((originx + x) >= mheight && (originy + y) >= mwidth){
                    matrix1[originy + (mwidth - y)][originx + (mheight - x)] = 1;
                }
                else if((originx + x) < 0){
                    matrix1[originy + y][originx + (mheight + x)] = 1;
                }
                else if((originy + y) < 0){
                    matrix1[originy + (mwidth + y)][originx + x] = 1;
                }
                else if((originy + y) < 0 && (originx + x) < 0){
                    matrix1[originy + (mwidth + y)][originx + (mheight + x)] = 1;
                }
                else{
                    matrix1[originy + y][originx + x] = 1;
                }
            }
            else{
                matrix1[originy + y][originx + x] = 1;
            }
        }
        title++;
    }
    fclose(start);
    return matrix1;
}

/**
 * Calls neighbor check in order to determine the next generations state
 * @param widthinc width incrementer
 * @param heightinc height incrementer
 * @return next
 */
unsigned char **next_gen(unsigned char **matrix, unsigned char **next, int width, int height, int edgetype)
{
    int widthinc;
    int heightinc;
	for(widthinc = 0; widthinc < width; widthinc++){
		for(heightinc = 0; heightinc < height; heightinc++){
			next = neighbor_check(matrix, next, width, height, widthinc, heightinc, edgetype);
		}
	}
    // if(edgetype == 1){
    //     for(i = 0; i < height; i++){
    //         next[0][i] = 0;
    //     }
    //     for(i = 0; i < height; i++){
    //         next[width - 1][i] = 0;
    //     }
    //     for(i = 0; i < width; i++){
    //         next[i][0] = 0;
    //     }
    //     for(i = 0; i < width; i++){
    //         next[i][height - 1] = 0;
    //     }
    // }
    // for(widthinc = 0; widthinc < width; widthinc++){
	// 	for(heightinc = 0; heightinc < height; heightinc++){
	// 		printf("%d", next[widthinc][heightinc]);
	// 	}
    //     printf("\n");
	// }
    return next;
}

/**
 * Calls one of the edge check functions depending on the edge type specified
 * @return next
 */
unsigned char **neighbor_check(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn, int edgetype)
{
    //printf("neighbor\n");
    switch (edgetype)
	{
		case 1:
			next = hedge_edge(matrix, next, width, height, currentrow, currentcolumn);
		break;
		case 2:
			next = torus_edge(matrix, next, width, height, currentrow, currentcolumn);
		break;
		case 3:
			next = klein_edge(matrix, next, width, height, currentrow, currentcolumn);
		break;
	}
    return next;
}

/**
 * Performs a check on each of the cells in the array and determines wether or
 * not that current cell will be alive in the next generation using the hedge
 * edge type.
 * @param widthinc width incrementer
 * @param heightinc height incrementer
 * @param count the count of alive cells near the current cell
 * @return next
 */
unsigned char **hedge_edge(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn)
{
    int widthinc;
    int heightinc;
    int count = 0;
    //printf("hedge\n");
    if(currentrow == 0 && currentcolumn == 0){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else if(currentrow == 0 && currentcolumn == (height - 1)){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else if(currentrow == (width - 1) && currentcolumn == 0){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else if(currentrow == (width - 1) && currentcolumn == (height - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else if(currentrow == 0 && currentcolumn != 0 && currentcolumn != (height - 1)){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else if(currentcolumn == 0 && currentrow != 0 && currentrow != (width - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else if(currentrow == (width - 1) && currentcolumn != 0 && currentcolumn != (height - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else if(currentcolumn == (height - 1) && currentrow != 0 && currentrow != (width - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    else{
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    count = count - matrix[currentrow][currentcolumn];
    if(matrix[currentrow][currentcolumn] == 1 && count < 2){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 1 && count >= 2 && count <=3){
        next[currentrow][currentcolumn] = 1;
    }
    if(matrix[currentrow][currentcolumn] == 1 && count > 3){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count == 3){
        next[currentrow][currentcolumn] = 1;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count < 3){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count > 3){
        next[currentrow][currentcolumn] = 0;
    }
    /**
    these go after the for that calls this function
    for(i = 0; i < height; i++){
        matrix[0][i] = 0;
    }
    for(i = 0; i < height; i++){
        matrix[height - 1][i] = 0;
    }
    for(i = 0; i < width; i++){
        matrix[i][0] = 0;
    }
    for(i = 0; i < width; i++){
        matrix[i][width - 1] = 0;
    }
    */
   return next;
}

/**
 * Performs a check on each of the cells in the array and determines wether or
 * not that current cell will be alive in the next generation using the torus
 * edge type.
 * @param widthinc width incrementer
 * @param heightinc height incrementer
 * @param count the count of alive cells near the current cell
 * @return next
 */
unsigned char **torus_edge(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn)
{
    int widthinc;
    int heightinc;
    int count = 0;

    if(currentrow == 0 && currentcolumn == 0){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[0][height - 1] + matrix[1][height-1];
        count = count + matrix[width - 1][height - 1] + matrix[width - 1][0] + matrix[width - 1][1];
    }
    else if(currentrow == 0 && currentcolumn == (height - 1)){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[width - 1][0] + matrix[0][0] + matrix[1][0] + matrix[width - 1][height - 1] + matrix[width -1][height - 2]; 
    }
    else if(currentrow == (width - 1) && currentcolumn == 0){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[0][height - 1] + matrix[0][0] + matrix[0][1] + matrix[width - 1][height - 1] + matrix[width - 2][height - 1];
    }
    else if(currentrow == (width - 1) && currentcolumn == (height - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[0][0] + matrix[0][height - 2] + matrix[0][height - 1] + matrix[width - 1][0] + matrix[width - 2][0];
    }
    else if(currentrow == 0 && currentcolumn != 0 && currentcolumn != (height - 1)){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
            count = count + matrix[width - 1][heightinc];
        }
    }
    else if(currentcolumn == 0 && currentrow != 0 && currentrow != (width - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            count = count + matrix[widthinc][height - 1];
        }
    }
    else if(currentrow == (width - 1) && currentcolumn != 0 && currentcolumn != (height - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
            count = count + matrix[0][heightinc];
        }
    }
    else if(currentcolumn == (height - 1) && currentrow != 0 && currentrow != (width - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            count = count + matrix[widthinc][0];
        }
    }
    else{
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    count = count - matrix[currentrow][currentcolumn];
    if(matrix[currentrow][currentcolumn] == 1 && count < 2){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 1 && count >= 2 && count <=3){
        next[currentrow][currentcolumn] = 1;
    }
    if(matrix[currentrow][currentcolumn] == 1 && count > 3){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count == 3){
        next[currentrow][currentcolumn] = 1;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count < 3){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count > 3){
        next[currentrow][currentcolumn] = 0;
    }
    return next;
}

/**
 * Performs a check on each of the cells in the array and determines wether or
 * not that current cell will be alive in the next generation using the klein
 * edge type.
 * @param widthinc width incrementer
 * @param heightinc height incrementer
 * @param count the count of alive cells near the current cell
 * @return next
 */
unsigned char **klein_edge(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn)
{
    int widthinc;
    int heightinc;
    int count = 0;

    if(currentrow == 0 && currentcolumn == 0){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[0][height - 1] + matrix[1][height-1];
        count = count + matrix[width - 1][height - 1] + matrix[width - 1][0] + matrix[width - 1][1];
    }
    else if(currentrow == 0 && currentcolumn == (height - 1)){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[width - 1][0] + matrix[0][0] + matrix[1][0] + matrix[width - 1][height - 1] + matrix[width -1][height - 2]; 
    }
    else if(currentrow == (width - 1) && currentcolumn == 0){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[0][height - 1] + matrix[0][0] + matrix[0][1] + matrix[width - 1][height - 1] + matrix[width - 2][height - 1];
    }
    else if(currentrow == (width - 1) && currentcolumn == (height - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        count = count + matrix[0][0] + matrix[0][height - 2] + matrix[0][height - 1] + matrix[width - 1][0] + matrix[width - 2][0];
    }
    else if(currentrow == 0 && currentcolumn != 0 && currentcolumn != (height - 1)){
        for(widthinc = currentrow; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(heightinc = ((height - currentcolumn) - 1); heightinc <= ((height - currentcolumn) + 1); heightinc++){
            count = count + matrix[width - 1][heightinc];
        }
    }
    else if(currentcolumn == 0 && currentrow != 0 && currentrow != (width - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            count = count + matrix[widthinc][height - 1];
        }
    }
    else if(currentrow == (width - 1) && currentcolumn != 0 && currentcolumn != (height - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(heightinc = ((height - currentcolumn) - 1); heightinc <= ((height - currentcolumn) + 1); heightinc++){
            count = count + matrix[0][heightinc];
        }
    }
    else if(currentcolumn == (height - 1) && currentrow != 0 && currentrow != (width - 1)){
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            count = count + matrix[widthinc][0];
        }
    }
    else{
        for(widthinc = currentrow - 1; widthinc <= currentrow + 1; widthinc++){
            for(heightinc = currentcolumn - 1; heightinc <= currentcolumn + 1; heightinc++){
                count = count + matrix[widthinc][heightinc];
            }
        }
    }
    count = count - matrix[currentrow][currentcolumn];
    if(matrix[currentrow][currentcolumn] == 1 && count < 2){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 1 && count >= 2 && count <=3){
        next[currentrow][currentcolumn] = 1;
    }
    if(matrix[currentrow][currentcolumn] == 1 && count > 3){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count == 3){
        next[currentrow][currentcolumn] = 1;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count < 3){
        next[currentrow][currentcolumn] = 0;
    }
    if(matrix[currentrow][currentcolumn] == 0 && count > 3){
        next[currentrow][currentcolumn] = 0;
    }
    return next;
}

/**
 * Frees both of the matrices after the program is done running
 */
void free_matrix(unsigned char **matrix, int width)
{
    int i;
    for(i = 0; i < width; i++){
        free(matrix[i]);
    }
    free(matrix);
    
}


