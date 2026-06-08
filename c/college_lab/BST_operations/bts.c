#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "bts.h"

Node* root = NULL;

Node* createNode(int ele) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = ele;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

void insert_children(Node* child, Node* parent) {
    while(true) {
        if (child->data > parent->data) {
            if (parent->rchild) {
                parent = parent->rchild;
                continue;
            }
            parent->rchild = child;
            return;
        }
        if (child->data < parent->data) {
            if (parent->lchild) {
                parent = parent->lchild;
                continue;
            }
            parent->lchild = child;
            return;
        }
    }
}

void insert(int ele) {
    
    if (!root) {
        root = createNode(ele);
        return;
    }

    Node* child = createNode(ele);
    insert_children(child, root);
}

void display(Node* ptr) {
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }

    if (ptr) {
        display(ptr->lchild);
        printf("%d ", ptr->data);
        display(ptr->rchild);
    }
}
