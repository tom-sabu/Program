#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node* stack[MAX];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    if (top == -1)
        return NULL;
    else
        return stack[top--];
}

char opStack[MAX];
int opTop = -1;

void pushOp(char c) {
    opStack[++opTop] = c;
}

char popOp() {
    if (opTop == -1)
        return -1;
    else
        return opStack[opTop--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalpha(c) || isdigit(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            pushOp(c);
        } else if (c == ')') {
            while (opTop != -1 && opStack[opTop] != '(') {
                postfix[j++] = popOp();
            }
            popOp();
        } else {
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(c)) {
                postfix[j++] = popOp();
            }
            pushOp(c);
        }
    }
    while (opTop != -1) {
        postfix[j++] = popOp();
    }
    postfix[j] = '\0';
}

struct Node* constructTree(char postfix[]) {
    struct Node *newNode, *t1, *t2;
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = c;
        newNode->left = newNode->right = NULL;
        if (isalpha(c) || isdigit(c)) {
            push(newNode);
        } else {
            t2 = pop();
            t1 = pop();
            newNode->right = t2;
            newNode->left = t1;
            push(newNode);
        }
    }
    return pop();
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    struct Node* root;
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    root = constructTree(postfix);
    printf("Prefix Expression (From Tree): ");
    preorder(root);
    printf("\n");
    printf("Postfix Expression (From Tree): ");
    postorder(root);
    printf("\n");
    return 0;
}
