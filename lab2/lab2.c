/**
 * @file lab2.c
 *
 * @author Caleb Krcil
 *
 * @date 9/14/2021
 *
 * Assignment: Lab 2
 *
 * @brief A program that uses the functions in functions.c.
 *
 * @details A program that takes user input and determines what geometry
 * calculation they want to do and what values to use in the calculation.
 * Then it calls the proper function from functions.c and computes the result
 * and takes the result and prints it to the user.
 *
 * @bug none
 *
 * @todo none
 */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char in()
{
        char tmp;
        while ((tmp = getchar()) != '\n')
        return tmp;
}

/**
 * 
 * Main function
 * Prints out the user interface of the program and asks for user to input
 * their calculation choice, then based on those choices it will call the
 * proper function and compute it based on the values that the user inputs
 * and prints the result of the calculation.
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
 * @param l length of the rectangle
 * @param w width of the rectangle
 * @param r radius of the circle
 * @param a height of the triangle
 * @param b base of the triangle
 * @param n number of sides of the polygon
 * @param s length of the sides of a regular polygon
 * @param A length of the apothem of a regular polygon
 * @return zero
 */
int main(void) {
        int l;
        int w;
        float r;
        float a;
        float b;
        int n;
        float s;
        float A;
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

        printf("        ------Welcome to Caleb's Calculator!!! (For Geometry)------\n\n");
        printf("Please select a geometry calculation:\n");
        printf("C. Circles\n");
        printf("P. Regular Polygons\n");
        printf("R. Rectangles\n");
        printf("T. Right Triangle\n\n");
        printf("Please enter your choice: (C, P, R, T)\n");
        char shape = in();
        getchar();

        switch(shape) {
        case 'c':
        case 'C':
                printf("Please select which calculation you want to do:\n");
                printf("A. Area of a Circle\n");
                printf("C. Circumference of a Circle\n");
                printf("Please enter your choice: (A, C) \n");
                char circle = in();
                getchar();
                switch(circle) {
                case 'A':
                case 'a':
                        printf("Enter the radius of the cirlce as a floating point number:\n");
                        scanf("%f", &r);
                        if(r < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        AC = area_circle(r);
                        printf("The area of the circle is: %lf\n", AC);
                break;
                case 'C':
                case 'c':
                        printf("Enter the radius of the cirlce as a floating point number:\n");
                        scanf("%f", &r);
                        if(r < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        c = circumference(r);
                        printf("The circumference of the circle is: %lf\n", c);
                break;
                default:
                        printf("Your input cannot be understood.\n");
                }
                break;
        case 'p':
        case 'P':
                printf("PLease select which calculation you want to do:\n");
                printf("E. Exterior Angle of a Regular Polygon\n");
                printf("I. Interior Angle of a Regular Polygon\n");
                printf("A. Area of a Regular Polygon\n");
                char poly = in();
                getchar();
                switch(poly) {
                case 'E':
                case 'e':
                        printf("Enter the number of sides of the regular polygon as an integer:\n");
                        scanf("%d", &n);
                        if(n < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        E = exterior_angle(n);
                        printf("The exterior angle of the polygon is: %lf\n", E);
                break;
                case 'I':
                case 'i':
                        printf("Enter the number of sides of the regular polygon as an integer:\n");
                        scanf("%d", &n);
                        if(n < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        I = interior_angle(n);
                        printf("The interior angle of the polygon in: %lf\n", I);                        
                break;
                case 'A':
                case 'a':
                        printf("Enter the number of sides of the regular polygon as an integer:\n");
                        scanf("%d", &n);
                        if(n < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        printf("Enter the length of the side of the regular polygon as a floating point number:\n");
                        scanf("%f", &s);
                        if(s < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        printf("Enter the length of the apothem of the regular polygon as a floating point number:\n");
                        scanf("%f", &A);
                        if(A < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        AP = area_regular_polygon(n, s, A);
                        printf("The area of the polygon is: %lf\n", AP);
                break;
                default:
                        printf("Your input cannot be understood.\n");
                }
                break;
        case 'r':
        case 'R':
                printf("Please select which calculation you want to do:\n");
                printf("A. Area of the Rectangle\n");
                printf("P. Perimeter of the Rectangle\n");
                char rect = in();
                getchar();
                switch(rect) {
                case 'A':
                case 'a':
                        printf("Enter the length of the rectangle as an integer:\n");
                        scanf("%d", &l);
                        if(l < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        printf("Enter the width of the rectangle as an integer:\n");
                        scanf("%d", &w);
                        if(w < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        R = area_rectangle(l, w);
                        printf("The area of the rectangle is: %lf\n", R);
                break;
                case 'P':
                case 'p':
                        printf("Enter the length of the rectangle as an integer:\n");
                        scanf("%d", &l);
                        if(l < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        printf("Enter the width of the rectangle as an integer:\n");
                        scanf("%d", &w);
                        if(w < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        RP = perimeter_rectangle(l, w);
                        printf("The perimeter of the rectangle is: %lf\n", RP);
                break;
                default:
                        printf("Your input cannot be understood.\n");
                }
                break;
        case 't':
        case 'T':
                printf("Please select which calculation you want to do:\n");
                printf("A. Area of a Right Triangle\n");
                printf("H. Hypotenuse of a Right Triangle\n");
                printf("P. Perimeter of a Right Triangle\n");
                char tri = in();
                getchar();
                switch(tri) {
                case 'A':
                case 'a':
                        printf("Enter the height of the triangle as a floating point number:\n");
                        scanf("%f", &a);
                        if(a < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        printf("Enter the base of the triangle as a floating point number:\n");
                        scanf("%f", &b);
                        if(b < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        AT = area_triangle(a, b);
                        printf("The area of the triangle is: %lf\n", AT);
                break;
                case 'H':
                case 'h':
                        printf("Enter the height of the triangle as a floating point number:\n");
                        scanf("%f", &a);
                        if(a < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        printf("Enter the base of the triangle as a floating point number:\n");
                        scanf("%f", &b);
                        if(b < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        C = hypotenuse(a, b);
                        printf("The hypotenuse of the triangle is %lf\n", C);
                break;
                case 'P':
                case 'p':
                        printf("Enter the height of the triangle as a floating point number:\n");
                        scanf("%f", &a);
                        if(a < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        printf("Enter the base of the triangle as a floating point number:\n");
                        scanf("%f", &b);
                        if(b < 0){
                                printf("Error: please input a positive number.\nBye now.\n");
                                exit(0);
                        }
                        TP = perimeter_triangle(a, b);
                        printf("The perimeter of the triangle is %lf\n", TP);
                break;
                default:
                        printf("Your input cannot be understood.\n");
                }
                break;
        default:
                printf("Your input cannot be understood.\n");
        }

        return 0;
}
