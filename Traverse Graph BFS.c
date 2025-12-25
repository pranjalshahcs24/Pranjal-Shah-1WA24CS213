/*
a) Write a program to traverse a graph using BFS method.
*/
#include <stdio.h>

#define MAX 10

// Global Variables
int adj[MAX][MAX];   // Adjacency Matrix
int visited[MAX];    // Visited Array (0 or 1)
int queue[MAX];      // Queue Array
int front = -1, rear = -1; // Queue Pointers
int n;               // Number of vertices

// Queue Operation: Enqueue
void enqueue(int v) {
    if (rear == MAX - 1)
        return; // Queue is full
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

// Queue Operation: Dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1; // Queue is empty
    return queue[front++];
}

// BFS Algorithm
void bfs(int start) {
    int i, current;

    // 1. Start by pushing the starting vertex to queue
    enqueue(start);
    visited[start] = 1; // Mark as visited

    printf("\nBFS Traversal: ");

    // 2. Loop until queue is empty
    while (front <= rear) {
        current = dequeue();
        printf("%d ", current);

        // 3. Check all neighbors of 'current'
        for (i = 0; i < n; i++) {
            // If there is an edge AND it hasn't been visited yet
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1; // Mark as visited immediately
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array to 0 (unvisited)
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
