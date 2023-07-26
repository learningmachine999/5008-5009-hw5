#include<stdio.h>
#include<stdlib.h>

#define SIZE 9
#define INFINITY 99999

void bfs(int graph[SIZE][SIZE], int start) {
    int visited[SIZE];
    for(int i = 0; i < SIZE; i++)
        visited[i] = 0;

    int queue[SIZE];
    int front = -1, rear = -1;

    // mark the start vertex as visited and enqueue it
    visited[start] = 1;
    queue[++rear] = start;

    while(front != rear) {
        int vertex = queue[++front]; // dequeue
        printf("%d ", vertex);

        // enqueue all adjacent vertices of the dequeued vertex
        for(int i = 0; i < SIZE; i++) {
            if(graph[vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0},  // 0
        {0, 0, 1, 0, 1, 0, 0, 0, 0},  // 1
        {0, 0, 0, 0, 0, 1, 0, 0, 0},  // 2
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 3
        {0, 0, 0, 0, 0, 0, 0, 1, 0},  // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 5
        {0, 0, 0, 0, 0, 0, 0, 1, 0},  // 6
        {0, 0, 0, 0, 0, 0, 0, 0, 1},  // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}   // 8
    };

    printf("Breadth First Search starting from vertex 0: ");
    bfs(graph, 0);

    return 0;
}