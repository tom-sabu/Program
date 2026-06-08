#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        return -1;
    }
    return stack[top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch, x;

    push('(');
    strcat(infix, ")");

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (ch == ' ') {
            continue;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (isOperator(ch)) {
            postfix[j++] = ' ';
            while (top >= 0 && precedence(peek()) >= precedence(ch)) {
                x = pop();
                postfix[j++] = x;
                postfix[j++] = ' ';
            }
            push(ch);
        }
        else if (ch == ')') {
            while (top >= 0 && peek() != '(') {
                x = pop();
                postfix[j++] = ' ';
                postfix[j++] = x;
            }
            if (top >= 0 && peek() == '(') {
                pop();
            }
        }
    }

    while (top >= 0 && peek() != '(') {
        postfix[j++] = ' ';
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
