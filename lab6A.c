/*WAP to Implement Single Link List with following
operations: Sort the linked list, Reverse the linked list,
Concatenation of two linked lists.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end
void insertEnd(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Sort linked list (Bubble Sort)
void sortList(struct Node* head) {
    if (head == NULL) return;

    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Reverse linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *next = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

// Concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 to List 1\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(&list1, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(&list2, value);
            break;

        case 3:
            printf("List 1: ");
            display(list1);
            break;

        case 4:
            printf("List 2: ");
            display(list2);
            break;

        case 5:
            sortList(list1);
            printf("List 1 Sorted.\n");
            break;

        case 6:
            list1 = reverseList(list1);
            printf("List 1 Reversed.\n");
            break;

        case 7:
            list1 = concatenate(list1, list2);
            printf("Lists concatenated (List2 appended to List1).\n");
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
