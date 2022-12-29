/**
 * @file lab5_q3.c
 *
 * @author Caleb Krcil
 *
 * @date 10/10/2021
 *
 * Assignment: Lab 5
 *
 * @brief finds manhattan and euclidean distances based on user input.
 *
 * @bugs none
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point1_t 
{
    double x;
    double y;
};

struct point2_t
{
    double x;
    double y;
};

/**
 * Main function
 * asks for user input for two x and y coordinates and assigns
 * them into their respective structs
 * @param e euclidean distance
 * @param m manhattan distance
 */
int main(void)
{
    double e;
    double m;
    double euclidean(struct point1_t point1, struct point2_t point2);
    double manhattan(struct point1_t point1, struct point2_t point2);

    struct point1_t point1;
    struct point2_t point2;

    printf("Input the starting point in the form x, y as a double.\n");
    scanf("%lf, %lf", &point1.x, &point1.y);
    printf("Input the ending point in the form x, y as a double.\n");
    scanf("%lf, %lf", &point2.x, &point2.y);

    e = euclidean(point1, point2);
    m = manhattan(point1, point2);

    printf("The euclidean distance is - %lf\n", e);
    printf("The manhattan distance is - %lf\n", m);

return 0;
}

/**
 * Finds the euclidean distance
 * @param euclidean euclidean distance
 * @return euclidean
 */
double euclidean(struct point1_t point1, struct point2_t point2)
{
    int euclidean;

    euclidean = sqrt(((point1.x - point2.x) * (point1.x - point2.x)) + ((point1.y - point2.y) * (point1.y - point2.y)));
    return euclidean;
}

/**
 * Finds the manhattan distance
 * @param manhattan manhattan distance
 * @return manhattan
 */
double manhattan(struct point1_t point1, struct point2_t point2)
{
    int manhattan;

    manhattan = abs((int) (point1.x - point2.x)) + abs((int) (point1.y - point2.y));
    return manhattan;
}