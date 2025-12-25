/*
a) WAP to simulate the working of a queue of integers
using an array. Provide the following operations: Insert,
Delete, Display
The programshould print appropriate messagesfor queue
empty and queue overflow conditions
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

void insert() {
    int item;
    // Check for Overflow
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert anymore.\n");
    } else {
        if (front == -1)
            front = 0; // If queue was empty, set front to 0

        printf("Enter value to insert: ");
        scanf("%d", &item);

        rear++;
        queue[rear] = item;
        printf("%d inserted into queue.\n", item);
    }
}

void delete() {
    // Check for Underflow
    if (front == -1 || front > rear) {
        printf("\nQueue Empty! Nothing to delete.\n");
    } else {
        printf("\nDeleted element: %d\n", queue[front]);
        front++;

        // Reset queue if it becomes empty to re-use space (Optional but good practice)
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
