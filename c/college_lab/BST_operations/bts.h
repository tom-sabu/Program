#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

extern Node* root;
void insert(int ele);
void insert_children(Node* child, Node* parent);
Node* createNode(int ele);
void display(Node* ptr);
void search(int ele);
Node* delete(Node* root, int ele);

#endif
