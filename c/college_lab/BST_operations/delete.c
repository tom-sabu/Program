#include <stdlib.h>
#include <stdbool.h>

#include "bts.h"

Node* delete (Node* root, int ele) {
    if (root == NULL) return root;

    if (ele > root->data) 
        root->rchild = delete (root->rchild, ele);
    else if (ele < root->data) 
        root->lchild = delete (root->lchild, ele);
    else {
        if (!root->rchild) {
            Node* temp = root->lchild;
            free(root);
            return temp;
        }
        if (!root->lchild) {
            Node* temp = root->rchild;
            free(root);
            return temp;
        }

        Node* succ = root->rchild;
        while (succ->lchild) succ = succ->lchild;

        root->data = succ->data;
        root->rchild = delete (root->rchild, succ->data);
    }
    return root;
}
