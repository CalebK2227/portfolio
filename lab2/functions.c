/**
 * @file functions.c
 *
 * @author Caleb Krcil
 *
 * @date 9/14/2021
 *
 * Assignment: Lab 2
 *
 * @brief contains the function definitions for lab 2
 *
 *
 * @bug none
 *
 * @todo none
 */

#include "functions.h"
#include <stdio.h>
#include <math.h>

/* Your functions go here */

/**
* Finds the area of a rectangle
* @param l The height of the triangle
* @param w The width of the triangle
* @return The product h * w
*/
int area_rectangle(int l, int w)
{
        return (l * w);
}

/**
 * Finds perimeter of a rectangle
 * @param l The height of the trianlge 
 * @param w the width of the triangle
 * @return the sum of 2l and 2w
 */
double perimeter_rectangle(int l, int w)
{
    return (2 * l) + (2 * w);
}

/**
 * This calculates the diagonal of a rectangle
 * @param l length of rectangle
 * @param w width of rectangle
 * @return the square root of l squared plus w squared
 */
double diagonal_rectangle(int l, int w)
{
    return sqrt(pow(l , 2) + pow(w , 2));
}

/**
 * This calculates the area of a circle
 * @param r radius of circle
 * @return the area of a circle for r
 */
double area_circle(float r)
{
    return M_PI * r * r;
}

/**
 * This calculates the circumference of a circle
 * @param r radius of circle
 * @return the circumference of a circle for r
 */
double circumference(float r)
{
    return M_PI * r * 2;
}

/**
 * This calculates the area of a triangle
 * @param a height of triangle
 * @param b base of triangle
 * @return the area of a triangle for a and b
 */
double area_triangle(float a, float b)
{
    return (a * b) / 2.0;
}

/**
 * This calculates the hypotenuse of a circle
 * @param a height of triangle
 * @param b base of triangle
 * @return the hypotenuse of a triangle for a and b
 */
double hypotenuse(float a, float b)
{
    return sqrt(pow(a , 2) + pow(b , 2));
}

/**
 * This calculates the perimeter of a triangle
 * @param a height of triangle
 * @param b base of triangle
 * the function also calls the previous function that calculates the 
 * hypotenuse
 * @return the perimeter of a triangle for a and b
 */
double perimeter_triangle(float a, float b)
{
    return (a + b + hypotenuse(a, b));
}

/**
 * This calculates the exterior angle measurement of a regular polygon
 * @param n number of sides of the polygon
 * @return the exterior angle for n
 */
double exterior_angle(int n)
{
    return 360 / n;
}

/**
 * This calculates the interior angle measurement of a regular polygon
 * @param n number of sides of the polygon
 * @return the interior angle for n
 */
double interior_angle(int n)
{
    return ((180 * n) - 360) / n;
}

/**
 * This calculates the area of a regular polygon
 * @param n number of sides of the polygon
 * @param s length of one of any of the sides of the polygon
 * @param A length of the apothem of the polygon
 * @return the area of a polygon for n, s, and A
 */
double area_regular_polygon(int n, float s, float A)
{
    return (n * s * A) / 2.0;
}