
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(char *url) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

Node* visitNewPage(Node *current, char *url) {
    Node *newNode = createNode(url);
    if (current != NULL) {
        Node *temp = current->next;
        while (temp != NULL) {
            Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = NULL;
        current->next = newNode;
        newNode->prev = current;
    }
    return newNode;
}

Node* goBack(Node *current) {
    if (current != NULL && current->prev != NULL) {
        return current->prev;
    }
    printf("No previous page!\n");
    return current;
}

Node* goForward(Node *current) {
    if (current != NULL && current->next != NULL) {
        return current->next;
    }
    printf("No forward page!\n");
    return current;
}

void displayCurrent(Node *current) {
    if (current == NULL) {
        printf("No pages visited yet!\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

void freeHistory(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *current = NULL;
    int choice;
    char url[100];

    printf("\n--- Web Browser Navigation ---\n");
    printf("1. Visit new page\n");
    printf("2. Go back\n");
    printf("3. Go forward\n");
    printf("4. Show current page\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = '\0';
                if (current == NULL) {
                    current = createNode(url);
                } else {
                    current = visitNewPage(current, url);
                }
                break;
            case 2:
                current = goBack(current);
                break;
            case 3:
                current = goForward(current);
                break;
            case 4:
                displayCurrent(current);
                break;
            case 5:
                printf("Exiting...\n");
                while (current && current->prev) {
                    current = current->prev;
                }
                freeHistory(current);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
