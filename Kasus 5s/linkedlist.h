#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data[20];
    struct node *next;
}Node;

Node* createNode(char value[]);

void insertLast(Node **head, char value[]);

void deleteFirst(Node **head);

void printList(Node *head);

#endif

