#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdbool.h>

#define MAX 100

typedef struct Node{
    char data;
    struct Node *left, *right;
} Node;

bool isOperator(char c);
Node* pop();
void push(Node* node);
Node* createNode(char data);
Node* buildTree(char postfix[]);
void prefix(Node* root);
void postfix(Node* root);
void freeTree(Node* root);

void infixToPostfix(char infix[], char postfix[]);
int precedence(char ch);

#endif
