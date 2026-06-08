#include "expression_tree.h"
#include <stdio.h>

int main() {
  char infix[MAX], postfixExp[MAX];
  Node *root = NULL;

  printf("Enter arithmetic expression (without spaces): ");
  scanf("%s", infix);

  infixToPostfix(infix, postfixExp);
  printf("Postfix expression: %s\n", postfixExp);

  root = buildTree(postfixExp);

  printf("Prefix equivalent: ");
  prefix(root);
  printf("\n");

  printf("Postfix equivalent: ");
  postfix(root);
  printf("\n");

  freeTree(root);
  return 0;
}
