/**
 * @file lab1.c
 * @brief This file calculates various geometric values based on the input of the user
 * 
 * @author Caleb Krcil
 * @date 9/2/2021
 * @bug No bugs
 */

#include<stdio.h>
#include<math.h>

/**
 * These define the integers and float numbers that the user inputs
 * and the code uses to calculate the geometric values
 */

int l;
int w;
float r;
float a;
float b;
int n;
float s;
float A;

/**
 * This defines the functions that are used to calculate the values
 * from the user input
 */

double area_rectangle(int l, int w);
double perimeter_rectangle(int l, int w);
double diagonal_rectangle(int l, int w);
double area_circle(float r);
double circumference(float r);
double area_triangle(float a, float b);
double hypotenuse(float a, float b);
double perimeter_triangle(float a, float b, double C);
double exterior_angle(int n);
double interior_angle(int n);
double area_regular_polygon(int n, float s, float A);

int main(void)
{
    /**
     * This defines the values that are calculated in the functions and
     * then printed back to the user
     * @param C Hypotenuse length
     * @param R Rectangle area
     * @param RP Rectangle perimeter
     * @param AC Circle area
     * @param c Circle circumference
     * @param AT Triangle area
     * @param TP Triangle perimeter
     * @param E Polygon exterior angle
     * @param I Polygon interior anlge
     * @param AP Polygon area
     */

    double C;
    double R;
    double RP;
    double AC;
    double c;
    double AT;
    double TP;
    double E;
    double I;
    double AP;

    /**
     * This is the user interface of the function, it prints out instructions
     * for the user to input and then scans that input and calls the below
     * functions in order to calculate it and then print the results
     * back to the user so that their geometry homework is easier.
     * Disclaimer- I am not responsible for any failing grades due to 
     * cheating or lack of work shown on homework etc.
     */

    printf("        ------Welcome to Caleb's Calculator!!! (For Geometry)------\n\n");
    printf("Enter the length of the rectangle as an integer:\n");
    scanf("%d", &l);
    printf("Enter the width of the rectangle as an integer:\n");
    scanf("%d", &w);
    R = area_rectangle(l, w);
    RP = perimeter_rectangle(l, w);
    printf("        ------Rectangle Calculations------\n\n");
    printf("The area of the rectangle is: %lf\n", R);
    printf("The perimeter of the rectangle is: %lf\n", RP);

    printf("Enter the radius of the cirlce as a floating point number:\n");
    scanf("%f", &r);
    AC = area_circle(r);
    c = circumference(r);
    printf("        ------Circle Calculations------\n\n");
    printf("The area of the circle is: %lf\n", AC);
    printf("The circumference of the circle is: %lf\n", c);

    printf("Enter the height of the triangle as a floating point number:\n");
    scanf("%f", &a);
    printf("Enter the base of the triangle as a floating point number:\n");
    scanf("%f", &b);
    AT = area_triangle(a, b);
    C = hypotenuse(a, b);
    TP = perimeter_triangle(a, b, C);
    printf("        ------Triangle Calculations------\n\n");
    printf("The area of the triangle is: %lf\n", AT);
    printf("The length of the hypotenuse is %lf\n", C);
    printf("The perimeter of the triangle is: %lf\n", TP);

    printf("Enter the number of sides of the regular polygon as an integer:\n");
    scanf("%d", &n);
    printf("Enter the length of the side of the regular polygon as a floating point number:\n");
    scanf("%f", &s);
    printf("Enter the length of the apothem of the regular polygon as a floating point number:\n");
    scanf("%f", &A);
    E = exterior_angle(n);
    I = interior_angle(n);
    AP = area_regular_polygon(n, s, A);
    printf("        ------Regular Polygon Calculations------\n\n");
    printf("The exterior angle of the polygon is: %lf\n", E);
    printf("The interior angle of the polygon is: %lf\n", I);
    printf("The area of the polygon is: %lf\n", AP);

    return 0;
}

/**
 * This calculates the area of a rectanlge
 * @param l length of rectangle
 * @param w width of rectangle
 */

double area_rectangle(int l, int w)
{
    return l * w;
}

/**
 * This calculates the perimeter of a rectangle 
 * @param l length of rectangle
 * @param w width of rectangle
 */

double perimeter_rectangle(int l, int w)
{
    return (2 * l) + (2 * w);
}

/**
 * This calculates the diagonal of a rectangle
 * @param l length of rectangle
 * @param w width of rectangle
 */

double diagonal_rectangle(int l, int w)
{
    return sqrt(pow(l , 2) + pow(w , 2));
}

/**
 * This calculates the area of a circle
 * @param r radius of circle
 */
double area_circle(float r)
{
    return M_PI * r * r;
}

/**
 * This calculates the circumference of a circle
 * @param r radius of circle
 */

double circumference(float r)
{
    return M_PI * r * 2;
}

/**
 * This calculates the area of a triangle
 * @param a height of triangle
 * @param b base of triangle
 */

double area_triangle(float a, float b)
{
    return (a * b) / 2.0;
}

/**
 * This calculates the hypotenuse of a circle
 * @param a height of triangle
 * @param b base of triangle
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
 */

double perimeter_triangle(float a, float b, double C)
{
    return (a + b + hypotenuse(a, b));
}

/**
 * This calculates the exterior angle measurement of a regular polygon
 * @param n number of sides of the polygon
 */

double exterior_angle(int n)
{
    return 360 / n;
}

/**
 * This calculates the interior angle measurement of a regular polygon
 * @param n number of sides of the polygon
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
 */

double area_regular_polygon(int n, float s, float A)
{
    return (n * s * A) / 2.0;
}