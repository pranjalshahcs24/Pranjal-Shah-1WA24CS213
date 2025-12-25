/*
b) Write a program to check whether given graph is
connected or not using DFS method
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Global variables
int adj[MAX][MAX]; // Adjacency Matrix
int visited[MAX];  // Visited Array
int n;             // Number of vertices

// DFS Recursive Function
void dfs(int vertex) {
    int i;

    // Mark the current node as visited
    visited[vertex] = 1;

    // Visit all unvisited neighbors
    for (i = 0; i < n; i++) {
        // Check if there is an edge (adj[vertex][i] == 1)
        // AND if the neighbor is not visited yet
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    bool isConnected = true;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize visited array to 0 (unvisited)
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // 1. Run DFS starting from the first vertex (0)
    dfs(0);

    // 2. Check if any vertex was left unvisited
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            isConnected = false;
            break; // Found an unvisited node, stop checking
        }
    }

    if (isConnected) {
        printf("\nThe graph is Connected.\n");
    } else {
        printf("\nThe graph is Not Connected.\n");
    }

    return 0;
}
