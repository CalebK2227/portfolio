/**
 * @file lab8.c
 *
 * @author Caleb Krcil
 *
 * @date 11/6/2021
 *
 * Assignment: Lab 8
 *
 * @brief a program that creates a linked list based on user input and can
 * then perform operations based on the list.
 * 
 * @details takes user input and creates a linked list based on that input.
 * It can also delete parts of the list, print out the list, count the
 * elements in the list and will then free all the allocated data.
 * 
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define LEN 10000

struct node_t {
    double x;
    struct node_t *next;
};

struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos);
int count_nodes(struct node_t *head);
struct node_t *find_node(struct node_t *head, double n);
struct node_t *delete_node(struct node_t *head, double n);
void delete_list(struct node_t *head);

/**
 * The main menu system for the program. Calls other functions based on user
 * input.
 * @param head struct for the linked list
 * @param buf array for holding user input
 * @param choice users choice
 * @param p wherever the user wants to input their number
 * @param pos where in the middle the user wants to input their number
 * @param n the number the user is adding
 * @param count how many nodes are in the list
 * @return zero
 */
int main(void)
{
    struct node_t *head = NULL;
    char buf[LEN];
    int choice;
    int p;
    int pos;
    double n;
    int count;
    while (1) {
        printf("Enter your choice\n");
        printf("1) Enter a new number\n");
        printf("2) Delete a number\n");
        printf("3) Print all numbers\n");
        printf("4) Tell how many numbers are in the list\n");
        printf("5) Find if a number is in the list\n");
        printf("6) Quit\n");
        fgets(buf, LEN, stdin);
        choice = atoi(buf);

        switch (choice){
            case 1:
                printf("Where do you want to add your number?\n");
                printf("1) Head of the list\n");
                printf("2) Somewhere in the middle\n");
                printf("3) Tail of the list\n");
                fgets(buf, LEN, stdin);
                p = atoi(buf);
                switch(p){
                    case 1:
                        printf("Enter the number you want to add\n");
                        fgets(buf, LEN, stdin);
                        n = atof(buf);
                        head = insert_head(head, create_node(n));
                    break;
                    case 2:
                        printf("Enter the number you want to add\n");
                        fgets(buf, LEN, stdin);
                        n = atof(buf);
                        printf("Enter where you want to add the number\n");
                        fgets(buf, LEN, stdin);
                        pos = atoi(buf);
                        head = insert_middle(head, create_node(n), pos);
                    break;
                    case 3:
                        printf("Enter the number you want to add\n");
                        fgets(buf, LEN, stdin);
                        n = atof(buf);
                        head = insert_tail(head, create_node(n));
                    break;
                    default:
                        printf("I cannot read your input\n");
                    break;
                }
            break;
            case 2:
                printf("Enter the number you want to delete\n");
                fgets(buf, LEN, stdin);
                n = atof(buf);
                head = delete_node(head, n);
            break;
            case 3:
                print_list(head);
            break;
            case 4:
                count = count_nodes(head);
                printf("There are %d nodes in this list\n", count);
            break;
            case 5:
                printf("Enter the number you want to find in the list\n");
                fgets(buf, LEN, stdin);
                n = atof(buf);
                print_node(find_node(head, n));

            break;
            case 6:
                delete_list(head);
                printf("Laters\n");
                exit(EXIT_SUCCESS);
            break;
            default:
                printf("I cannot read your input\n");
            break;
        }
    }
    return 0;
}

/**
 * creates a node with the user input number stored in it
 * @param t the node created
 * @return t
 */
struct node_t *create_node(double n)
{
    struct node_t *t;
    t = NULL;
    t = malloc(sizeof(struct node_t));
    if ( t == NULL )
    {
        printf("Error: out of memory.\n");
        return 0;
    }
    t->x = n;
    t->next = NULL;
    print_node(t);
    return t;
}

/**
 * inserts a node at the head of the list
 * @return node
 */
struct node_t *insert_head(struct node_t *head, struct node_t *node)
{
    node->next = head;
    return node;
}

/**
 * inserts a node at the tail of the list
 * @param tmp temporary node holder
 * @return head
 */
struct node_t *insert_tail(struct node_t *head, struct node_t *node)
{
    if(head == NULL){
        return insert_head(head, node);
    }
    struct node_t *tmp;
    tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = node;
    return head;
}

/**
 * inserts a node in the middle of the list
 * @param tmp temporary node holder
 * @param i iterating value
 * @return head
 */
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos)
{
    if(head == NULL){
        return insert_head(head, node);
    }
    struct node_t *tmp;
    tmp = head;
    int i;
    i = 0;
    while(tmp->next != NULL && i < (pos - 2)){
        tmp = tmp->next;
        i++;
    }
    node->next = tmp->next;
    tmp->next = node;
    return head;
}

/**
 * Deletes and frees the list
 * @param tmp temporary node holder
 * @param ttmp temporary node holder
 */
void delete_list(struct node_t *head)
{
    struct node_t *tmp;
    struct node_t *ttmp;

    tmp = head;
    if(tmp == NULL){
        return;
    }
    while(tmp->next != NULL){
        ttmp = tmp;
        tmp = tmp->next;
        free(ttmp);
    }
    free(tmp);
}

/**
 * prints out a node
 */
void print_node(struct node_t *node)
{
    if(node == NULL){
        printf("The number was not found in the list\n");
        return;
    }
    printf("This is the value stored %lf\n", node->x);
    printf("This is the address of the node %p\n", node);
    if (node->next == NULL){
        printf("The address next points to is NULL\n");
    }
    else{
        printf("This is the address that next points to %p\n", node->next);
    }
}

/**
 * prints out the list
 * @param tmp temporary node holder
 */
void print_list(struct node_t *head)
{
    struct node_t *tmp;
    tmp = head;
    if(tmp == NULL){
        return;
    }
    print_node(tmp);
    while(tmp->next != NULL){
        tmp = tmp->next;
        print_node(tmp);
    }
}

/**
 * counts the node in the list
 * @param tmp temporary node holder
 * @param i count of nodes
 * @return i
 * @return 0
 */
int count_nodes(struct node_t *head)
{
    struct node_t *tmp;
    tmp = head;
    int i = 1;
    if(head == NULL){
        return 0;
    }
    while(tmp->next != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}

/**
 * deletes a selected node
 * @param tmp temporary node holder
 * @param node temporary node holder
 * @return head
 * @return node
 */
struct node_t *delete_node(struct node_t *head, double n)
{
    struct node_t *tmp;
    tmp = head;
    struct node_t *node;
    node = head;
    if(head->x == n){
        node = head->next;
        free(head);
        return node;
    }
    while(tmp->next != NULL){
        if(tmp->next->x == n){
            node = tmp->next;
            tmp->next = node->next;
            free(node);
            return head; 
        }
    }
    
    return head;
}

/**
 * finds if a number is in the list
 * @param tmp temporary node holder
 * @return tmp
 * @return NULL
 */
struct node_t *find_node(struct node_t *head, double n)
{
    struct node_t *tmp;
    tmp = head;
    if(head == NULL){
        return NULL;
    }
    while(tmp->next != NULL){
        if(isgreaterequal(tmp->x, n) && islessequal(tmp->x, n)){
            printf("The number was found in the list--\n");
            return tmp;
        }
        tmp = tmp->next;
    }
    if(isgreaterequal(tmp->x, n) && islessequal(tmp->x, n)){
        printf("The number was found in the list--\n");
        return tmp;
    }
    return NULL;
}