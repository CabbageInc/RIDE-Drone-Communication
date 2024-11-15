#include "List.h"

Node* createNode(void* data, size_t dataSize) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    newNode->data = malloc(dataSize);
    if (newNode->data == NULL) {
        printf("Memory allocation for data failed\n");
        free(newNode);
        return NULL;
    }

    // Copy the data into the node
    memcpy(newNode->data, data, dataSize);
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, void* data, size_t dataSize) {
    Node* newNode = createNode(data, dataSize);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head, void (*printFunc)(void*)) {
    Node* temp = head;
    while (temp != NULL) {
        printFunc(temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}
