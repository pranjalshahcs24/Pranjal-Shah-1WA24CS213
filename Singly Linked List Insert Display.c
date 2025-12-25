/*
WAP to Implement Singly Linked List with following
operations
a) Create a linked list.
b) Deletion of first element, specified element and last
element in the list.
c) Display the contents of the linked list.
*/


#include <stdio.h>
#include <stdlib.h>

// Define the Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Global Head Pointer
struct Node* head = NULL;

// Helper function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// a) Create List
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = NULL; // Reset head for new list

    if(n <= 0) return;

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;

    for(i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);
        temp->next = newNode;
        temp = temp->next;
    }
    printf("List created successfully.\n");
}

// b1) Delete First Element
void deleteFirst() {
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next; // Move head to the next node

    printf("Deleted element: %d\n", temp->data);
    free(temp); // Free memory to avoid leaks
}

// b2) Delete Last Element
void deleteLast() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Special Case: Only one node in list
    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Traverse to the end
    temp = head;
    while (temp->next != NULL) {
        prev = temp;       // Keep track of the node before temp
        temp = temp->next;
    }

    // temp is now the last node, prev is the second to last
    prev->next = NULL; // Unlink the last node
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// b3) Delete Specified Element (by Value)
void deleteSpecific(int key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: Head holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Changed head
        printf("Deleted element: %d\n", key);
        free(temp);
        return;
    }

    // Case 2: Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present
    if (temp == NULL) {
        printf("Element %d not found in list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    printf("Deleted element: %d\n", key);
    free(temp);
}

// c) Display
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, key;

    while(1) {
        printf("\n--- DELETION OPERATIONS ---\n");
        printf("1. Create List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Last Element\n");
        printf("4. Delete Specific Element\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2: deleteFirst(); break;
            case 3: deleteLast(); break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteSpecific(key);
                break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
