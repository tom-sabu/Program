#include "expression_tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node *stack[MAX];
int top = -1;

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

Node *pop() { return stack[top--]; }

void push(Node *node) { stack[++top] = node; }

Node *createNode(char data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *buildTree(char postfix[]) {
  for (int i = 0; postfix[i] != '\0'; i++) {
    Node *newNode = createNode(postfix[i]);

    if (isOperator(postfix[i])) {
      newNode->right = pop();
      newNode->left = pop();
    }
    push(newNode);
  }
  return pop();
}

void prefix(Node *root) {
  if (root) {
    printf("%c ", root->data);
    prefix(root->left);
    prefix(root->right);
  }
}

void postfix(Node *root) {
  if (root) {
    postfix(root->left);
    postfix(root->right);
    printf("%c ", root->data);
  }
}

void freeTree(Node *root) {
  if (root) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}
