/**
 * @file life.h
 * 
 * @author Caleb Krcil
 * 
 * @date 11/27/2021
 * 
 * @brief header file for life.c
 */
#ifndef LIFE_H_
#define LIFE_H_

unsigned char **init_matrix(int width, int height);
unsigned char **fileset(unsigned char **matrix1, char* file, int mwidth, int mheight, int originx, int originy, int edgetype);
unsigned char **next_gen(unsigned char **matrix, unsigned char **next, int width, int height, int edgetype);
unsigned char **neighbor_check(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn, int edgetype);
unsigned char **hedge_edge(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn);
unsigned char **torus_edge(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn);
unsigned char **klein_edge(unsigned char **matrix, unsigned char **next, int width, int height, int currentrow, int currentcolumn);
void free_matrix(unsigned char **matrix, int width);

#endif
