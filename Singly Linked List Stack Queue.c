/*
b) WAP to Implement Single Link List to simulate Stack &
Queue Operations.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global Pointers for Stack
struct Node* top = NULL;

// Global Pointers for Queue
struct Node* front = NULL;
struct Node* rear = NULL;

// --- STACK OPERATIONS (LIFO) ---

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // Link new node to the current top
    newNode->next = top;
    // Update top to point to the new node
    top = newNode;

    printf("Stack Push: %d\n", value);
}

void pop() {
    struct Node* temp;
    if (top == NULL) {
        printf("Stack Underflow! (Empty)\n");
        return;
    }

    temp = top;
    top = top->next; // Move top to the next node

    printf("Stack Pop: %d\n", temp->data);
    free(temp);
}

void displayStack() {
    struct Node* temp = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// --- QUEUE OPERATIONS (FIFO) ---

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, front and rear both point to new node
    if (front == NULL) {
        front = rear = newNode;
    } else {
        // Link the current rear to the new node
        rear->next = newNode;
        // Move rear to the new node
        rear = newNode;
    }
    printf("Queue Enqueue: %d\n", value);
}

void dequeue() {
    struct Node* temp;
    if (front == NULL) {
        printf("Queue Underflow! (Empty)\n");
        return;
    }

    temp = front;
    front = front->next; // Move front to the next node

    // If front becomes NULL, rear must also be NULL (queue is empty)
    if (front == NULL) {
        rear = NULL;
    }

    printf("Queue Dequeue: %d\n", temp->data);
    free(temp);
}

void displayQueue() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// --- MAIN MENU ---

int main() {
    int choice, val;

    while (1) {
        printf("\n--- LINKED LIST SIMULATION ---\n");
        printf("1. Stack Push\n");
        printf("2. Stack Pop\n");
        printf("3. Stack Display\n");
        printf("----------------\n");
        printf("4. Queue Enqueue\n");
        printf("5. Queue Dequeue\n");
        printf("6. Queue Display\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: pop(); break;
            case 3: displayStack(); break;

            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;

            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
