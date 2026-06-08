#include <ctype.h>
#include <stdio.h>

#define SIZE 30

char infix[SIZE];
char postfix[SIZE];
char stack[SIZE];
int top = -1;
int postfix_point = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop()
{
    char pop_element = stack[top--];
    return pop_element;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infix_to_postfix() {
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            push(infix[i]);

        else if (isalpha(infix[i])) {
            postfix[++postfix_point] = infix[i];
        }

        else if (infix[i] == ')') {
            while(stack[top] != '(')
            {
                postfix[++postfix_point] = pop();
            }
            pop();
        }

        else {
            if (precedence(infix[i]) > precedence(stack[top]))
                push(infix[i]);
            else {
                postfix[++postfix_point] = pop();
                push(infix[i]);
            }
        } 
    }
    while(top != -1)
        postfix[++postfix_point] = pop();
}
int main() {
    printf("enter an infix expression: ");
    scanf("%s", infix);
    infix_to_postfix();

    printf("After conversion: %s\n", postfix);

    return 0;
}
