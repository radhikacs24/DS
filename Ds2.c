#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
};

/* Recursive function to find minimum element */
int findMin(struct Node *head) {
    if (head == NULL)
        return INT_MAX;

    int minRest = findMin(head->next);
    return (head->data < minRest) ? head->data : minRest;
}

/* Recursive function to find maximum element */
int findMax(struct Node *head) {
    if (head == NULL)
        return INT_MIN;

    int maxRest = findMax(head->next);
    return (head->data > maxRest) ? head->data : maxRest;
}

/* Helper function to create a node */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* MAIN FUNCTION (Required) */
int main() {
    struct Node *head = createNode(10);
    head->next = createNode(5);
    head->next->next = createNode(30);
    head->next->next->next = createNode(2);

    printf("Minimum element: %d\n", findMin(head));
    printf("Maximum element: %d\n", findMax(head));

    return 0;
}
