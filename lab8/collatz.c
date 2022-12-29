/**
 * @file collatz.c
 *
 * @author Caleb Krcil
 *
 * @date 11/6/2021
 *
 * Assignment: Lab 8
 *
 * @brief a program that creates a linked list of the hailstone sequence of a
 * user input number and prints it out,
 * 
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 100

struct node_t {
    int s;
    struct node_t *next;
};
void delete_list(struct node_t *head);
void print_list(struct node_t *head);
int count_nodes(struct node_t *head);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t *create_node(int n);

/**
 * Main menu for the program, calls functions after user input
 * @param head struct for the node
 * @param buf array for holding user input
 * @param n number that user want the sequence for
 * @param s modified version of the input number
 * @return zero
 */
int main(void)
{
    struct node_t *head = NULL;
    char buf[LEN];
    int n;
    int s;

    printf("Enter the number that you want the hailstone sequence for\n");
    fgets(buf, LEN, stdin);
    n = atoi(buf);

    head = insert_head(head, create_node(n));
    if(n % 2 == 0){
        s = (n / 2);
        head = insert_tail(head, create_node(s));
    }
    else{
        s = ((n * 3) + 1);
        head = insert_tail(head, create_node(s));
    }
    while(s != 1){
        if(s % 2 == 0){
            s = (s / 2);
            head = insert_tail(head, create_node(s));
        }
        else{
            s = ((s * 3) + 1);
            head = insert_tail(head, create_node(s));
        }
    }

    printf("Cycle length = %d\n", count_nodes(head));
    print_list(head);
    delete_list(head);

}

/**
 * creates a node with the user input or modified number stored in it
 * @param t the node created
 * @return t
 */
struct node_t *create_node(int n)
{
    struct node_t *t;
    t = NULL;
    t = malloc(sizeof(struct node_t));
    if ( t == NULL )
    {
        printf("Error: out of memory.\n");
        return 0;
    }
    t->s = n;
    t->next = NULL;
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
 * prints out the sequence
 * @param tmp temporary node holder
 */
void print_list(struct node_t *head)
{
    struct node_t *tmp;
    tmp = head;
    printf("%d", tmp->s);
    while(tmp->next != NULL){
        tmp = tmp->next;
        printf(", %d", tmp->s);
    }
    printf("\n");
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