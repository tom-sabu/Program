#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int cqueue[MAX];
int rear = -1;
int front = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % MAX == front;
}

void insert() {
    int item;
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        printf("Insert the element in queue: ");
        scanf("%d", &item);

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        cqueue[rear] = item;
    }
}

void delete() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Element deleted from queue is: %d\n", cqueue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue is: ");
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX)
        printf("%d ", cqueue[i]);
    printf("%d\n", cqueue[i]);
}
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return cqueue[front];
}
int main() {
    int choice;
    printf("\n1. Insert element to queue\n");
    printf("2. Delete element from queue\n");
    printf("3. Display all elements of queue\n");
    printf("4. Peek\n");
    printf("5. Quit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: {
                int x = peek();
                if (x != -1)
                    printf("Front element is = %d\n", x);
                break;
            }
            case 5: exit(0);
            default: printf("Wrong choice\n");
        }
    } return 0;}

