/*
WAP to simulate the working of a circular queue of
integers using an array. Provide the following operations:
Insert, Delete & Display
The programshould print appropriate messagesfor queue
empty and queue overflow conditions
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

int cqueue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;

    // Check for Overflow: If the next position is front, the circle is full
    if ((rear + 1) % MAX == front) {
        printf("\nCircular Queue Overflow! Cannot insert.\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &item);

        // If queue is empty, initialize front and rear
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            // Move rear to next position (wrap around using modulo)
            rear = (rear + 1) % MAX;
        }

        cqueue[rear] = item;
        printf("%d inserted.\n", item);
    }
}

void delete() {
    // Check for Underflow
    if (front == -1) {
        printf("\nCircular Queue Empty! Nothing to delete.\n");
    } else {
        printf("\nDeleted element: %d\n", cqueue[front]);

        // If there was only one element, reset queue to empty state
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Move front to next position (wrap around)
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("\nCircular Queue is empty.\n");
    } else {
        printf("\nQueue elements: ");

        // Loop from front until we hit rear
        i = front;
        while (i != rear) {
            printf("%d ", cqueue[i]);
            i = (i + 1) % MAX;
        }
        // Print the last element (at rear)
        printf("%d \n", cqueue[rear]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
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
