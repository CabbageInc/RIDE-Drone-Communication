#ifndef INC_LIST_H_
#define INC_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;           // Generic pointer to hold any type of data
    struct Node* next;
} Node;

// create a new node
Node* createNode(void* data, size_t dataSize);

// add the node to the end of the list
void insertAtEnd(Node** head, void* data, size_t dataSize);

// print the whole list to the console (requires a helper function)
void printList(Node* head, void (*printFunc)(void*));

// delete the dynamic memory of the list
void freeList(Node* head);

#endif // INC_LIST_H_