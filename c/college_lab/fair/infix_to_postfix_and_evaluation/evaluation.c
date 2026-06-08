#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    char symbol;
    int operand1, operand2, result;
    char numStr[20];
    int numIndex = 0;

    while (postfix[i] != '\0') {
        symbol = postfix[i];

        if (symbol == ' ') {
            i++;
            continue;
        }

        if (isdigit(symbol)) {
            numIndex = 0;
            while (isdigit(postfix[i])) {
                numStr[numIndex++] = postfix[i++];
            }
            numStr[numIndex] = '\0';
            push(atoi(numStr));
        }
        else if (isOperator(symbol)) {
            operand2 = pop();
            operand1 = pop();

            if (operand1 == -1 || operand2 == -1) {
                printf("Error: Invalid expression\n");
                return -1;
            }

            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < operand2; j++) {
                        result *= operand1;
                    }
                    break;
            }
            push(result);
            i++;
        }
        else {
            i++;
        }
    }

    result = pop();

    if (top != -1) {
        printf("Error: Invalid expression\n");
        return -1;
    }

    return result;
}

int main() {
    char postfix[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Postfix Expression: %s\n", postfix);

    top = -1;
    result = evaluatePostfix(postfix);

    if (result != -1) {
        printf("Evaluation Result: %d\n", result);
    }

    return 0;
}
