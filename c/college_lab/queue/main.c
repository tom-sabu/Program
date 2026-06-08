#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int size;
    int rear;
    int front;
}Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, int item);
void dequeue(Queue* q);
bool isFull(Queue* q);
bool isEmpty(Queue* q);

int main() {
    int ch, ele;
    Queue q;
    initQueue(&q);

    printf("1.ins, 2.del, 3.exit:\n");
    while (true) {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);

                enqueue(&q, ele);
                break;

            case 2:
                dequeue(&q);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid input:");
        }
    }
}

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = item;
    q->size++;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front = (q->front +1) % MAX_SIZE;
    q->size--;
}