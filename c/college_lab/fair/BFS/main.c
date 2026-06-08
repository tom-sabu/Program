#include <stdio.h>

#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}


void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int v;
    printf("BFS Traversal: ");
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        v = dequeue();
        printf("%d ", v + 1);
        for (int u = 0; u < n; u++) {
            if (adj[v][u] == 1 && visited[u] == 0) {
                visited[u] = 1;
                enqueue(u);
            }
        }
    }
    printf("\n");
}


int main() {
    int adj[MAX][MAX];

    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex (1 to %d): ", n);
    scanf("%d", &start);
    BFS(adj, n, start - 1);
    return 0;
}
