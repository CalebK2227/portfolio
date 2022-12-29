/**
 * @file zombie.h
 * 
 * @author Caleb Krcil
 *
 * @date 10/21/2021
 *  
 * Assignment: Lab 6 
 *
 * @brief header file for zombie.c
 *
 * @details see zombie.c for details
 *  
 * @bugs none
 *
 * @todo none
 */
#ifndef ZOMBIE_H
#define ZOMBIE_H

struct zombie {
    enum {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY}
    day;
    float blood;
    int toes;
    int hour;
    int min;
    int sec;
    char dead;
};
struct zombie input_time(struct zombie z[], int i);
struct zombie input_toes(struct zombie z[], int i);
struct zombie input_blood(struct zombie z[], int i);
void print_zombies(struct zombie z[]);


#endif