#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1 && rear == -1;
}

bool isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void insertAtRear() {
    if (isFull()) {
        printf("Overflow at rear\n");
        return;
    }
    
    int item;
    printf("Enter element to insert at rear: ");
    scanf("%d", &item);
    
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    
    deque[rear] = item;
    printf("Element %d inserted at rear successfully\n", item);
}

void deleteFromFront() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    
    printf("Element %d deleted from front\n", deque[front]);
    
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void insertAtFront() {
    if (isFull()) {
        printf("Overflow at front\n");
        return;
    }
    
    int item;
    printf("Enter element to insert at front: ");
    scanf("%d", &item);
    
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    
    deque[front] = item;
    printf("Element %d inserted at front successfully\n", item);
}

void deleteFromRear() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    
    printf("Element %d deleted from rear\n", deque[rear]);
    
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    
    printf("Deque elements: ");
    int i = front;
    
    if (front <= rear) {
        while (i <= rear) {
            printf("%d ", deque[i]);
            i++;
        }
    } else {
        while (i < MAX) {
            printf("%d ", deque[i]);
            i++;
        }
        i = 0;
        while (i <= rear) {
            printf("%d ", deque[i]);
            i++;
        }
    }
    printf("\n");
}

void peekFront() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", deque[front]);
}

void peekRear() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Rear element: %d\n", deque[rear]);
}

int size() {
    if (isEmpty()) {
        return 0;
    }
    
    if (front <= rear) {
        return rear - front + 1;
    } else {
        return (MAX - front) + (rear + 1);
    }
}

int main() {
    int choice;
    
    printf("Double Ended Queue Operations\n");
    printf("1. Insert at Rear\n");
    printf("2. Delete from Front\n");
    printf("3. Insert at Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Display\n");
    printf("6. Peek Front\n");
    printf("7. Peek Rear\n");
    printf("8. Size\n");
    printf("9. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertAtRear();
                break;
            case 2:
                deleteFromFront();
                break;
            case 3:
                insertAtFront();
                break;
            case 4:
                deleteFromRear();
                break;
            case 5:
                display();
                break;
            case 6:
                peekFront();
                break;
            case 7:
                peekRear();
                break;
            case 8:
                printf("Deque size: %d\n", size());
                break;
            case 9:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
