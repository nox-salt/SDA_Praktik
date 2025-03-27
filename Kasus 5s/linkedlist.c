#include "linkedlist.h"
#include <string.h>


Node* createNode(char value[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        strcpy(newNode->data, value);
        newNode->next = NULL;
    }
    return newNode;
}


void insertLast(Node **head, char value[]) {
    Node *newNode = createNode(value);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteFirst(Node **head) {
    if (*head) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}


void printList(Node *head) {
    Node *temp = head;
    while (temp) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


