#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *previous;
};

struct node *head;

struct node *createNode(int x) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = NULL;
  newNode->previous = NULL;
  return newNode;
}

void insertAtHead(int x) {
  struct node *newNode = createNode(x);
  if (head == NULL) {
    head = newNode;
    return;
  }
  head->previous = newNode;
  newNode->next = head;
  head = newNode;
}

void insertAtTail(int x) {
  struct node *newNode = createNode(x);
  if (head == NULL) {
    head = newNode;
    return;
  }
  struct node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newNode;
  newNode->previous = temp;
}

void print() {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int n, choise, data;

  printf("Enter the nubmer of data's you are going to enter : ");
  scanf("%d", &n);

  printf("Enter the number according to the operation you want to perform\n1. "
         "Insert at the head\n2. Insert at the tail\n\n");
  while (n != 0) {
    n--;
    printf("Choise: ");
    scanf("%d", &choise);

    switch (choise) {
    case 1:
      printf("enter the data : ");
      scanf("%d", &data);
      insertAtHead(data);
      break;

    case 2:
      printf("enter the data : ");
      scanf("%d", &data);
      insertAtTail(data);
      break;

    default:
      printf("Wrong choise, Enter again\n");
    }
  }

  print();

  return 0;
}
