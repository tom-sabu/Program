#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == rear;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue() {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    
    int item;
    printf("Enter element to enqueue: ");
    scanf("%d", &item);
    
    rear++;
    queue[rear] = item;
    printf("Element %d enqueued successfully\n", item);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    
    front++;
    printf("Element %d dequeued successfully\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front + 1; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Front element: %d\n", queue[front + 1]);
}

int size() {
    if (isEmpty()) {
        return 0;
    }
    return rear - front;
}

int main() {
    int choice;
    
    printf("Linear Queue Operations\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Peek\n");
    printf("5. Size\n");
    printf("6. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Queue size: %d\n", size());
                break;
            case 6:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
