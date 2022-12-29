/**
 * @file functions.h
 *
 * @author caleb Krcil
 *
 * @date 9/14/2021
 *
 * Assignment: Lab 2
 *
 * @brief header file for functions.c
 *
 * @details see functions.c for details
 *
 * @bugs
 * @todo none
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* You may need #include <> statements here */

#include <stdio.h>
#include <math.h>

/* Function prototyes go here */
int area_rectangle(int l, int w);
double perimeter_rectangle(int l, int w);
double diagonal_rectangle(int l, int w);
double area_circle(float r);
double circumference(float r);
double area_triangle(float a, float b);
double hypotenuse(float a, float b);
double perimeter_triangle(float a, float b);
double exterior_angle(int n);
double interior_angle(int n);
double area_regular_polygon(int n, float s, float A);


#endif
