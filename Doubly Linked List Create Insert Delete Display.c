/*
WAP to Implement doubly link list with primitive
operations
a) Create a doubly linked list.
b) Insert a new node to the left of the node.
c) Delete the node based on a specific value
d) Display the contents of the list
*/

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev; // Pointer to previous node
    struct Node* next; // Pointer to next node
};

// Global Head Pointer
struct Node* head = NULL;

// Helper function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a) Create a Doubly Linked List
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = NULL;

    if (n <= 0) return;

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = createNode(data);

        // Link the nodes
        temp->next = newNode;   // Previous node points to new node
        newNode->prev = temp;   // New node points back to previous node

        // Move temp forward
        temp = newNode;
    }
    printf("List created successfully.\n");
}

// b) Insert a new node to the LEFT of a specific node
void insertLeft() {
    int targetVal, newVal;
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the value of the target node (to insert left of): ");
    scanf("%d", &targetVal);

    // Find the target node
    while (temp != NULL && temp->data != targetVal) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target node %d not found.\n", targetVal);
        return;
    }

    printf("Enter new value to insert: ");
    scanf("%d", &newVal);
    struct Node* newNode = createNode(newVal);

    // Case 1: Inserting before the Head
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // Case 2: Inserting between two nodes
    else {
        newNode->prev = temp->prev; // New node points back to A
        newNode->next = temp;       // New node points forward to B (target)

        temp->prev->next = newNode; // A points forward to New Node
        temp->prev = newNode;       // B points back to New Node
    }
    printf("Node inserted successfully.\n");
}

// c) Delete a node based on specific value
void deleteNode() {
    int key;
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    // Search for the node
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    // Case 1: Deleting the Head
    if (temp == head) {
        head = head->next;
        if (head != NULL) { // If list had more than 1 node
            head->prev = NULL;
        }
    }
    // Case 2: Deleting a Middle or Last Node
    else {
        // Link the previous node to the next node
        temp->prev->next = temp->next;

        // If it's NOT the last node, link the next node back to the previous
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);
    printf("Node %d deleted.\n", key);
}

// d) Display the list
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nDoubly Linked List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST OPERATIONS ---\n");
        printf("1. Create List\n");
        printf("2. Insert Left of Node\n");
        printf("3. Delete Node (by Value)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2: insertLeft(); break;
            case 3: deleteNode(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
