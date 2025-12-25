/*
a) WAP to Implement Single Link List with following
operations: Sort the linked list, Reverse the linked list,
Concatenation of two linked lists.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a list with n nodes
struct Node* createList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int data, i;

    if (n <= 0) return NULL;

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

// Display function
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

// 1. Sort the Linked List (Bubble Sort method by swapping data)
void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL) return;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

// 2. Reverse the Linked List
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev one step forward
        current = next;       // Move current one step forward
    }
    printf("List reversed successfully.\n");
    return prev; // Prev is the new head
}

// 3. Concatenate Two Linked Lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    struct Node* temp;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    temp = head1;
    // Traverse to the last node of the first list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link last node of List 1 to head of List 2
    temp->next = head2;

    printf("Lists concatenated successfully.\n");
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, n;

    while (1) {
        printf("\n--- ADVANCED LIST OPERATIONS ---\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Sort List 1\n");
        printf("5. Reverse List 1\n");
        printf("6. Concatenate List 2 into List 1\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes for List 1: ");
                scanf("%d", &n);
                list1 = createList(n);
                break;
            case 2:
                printf("Enter number of nodes for List 2: ");
                scanf("%d", &n);
                list2 = createList(n);
                break;
            case 3:
                printf("List 1: ");
                display(list1);
                break;
            case 4:
                sortList(list1);
                break;
            case 5:
                list1 = reverseList(list1);
                break;
            case 6:
                list1 = concatenate(list1, list2);
                // After concatenation, list2 is part of list1
                // We set list2 to NULL to avoid double-freeing or confusion later
                list2 = NULL;
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
