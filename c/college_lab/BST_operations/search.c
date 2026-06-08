#include <stdio.h>
#include <stdbool.h>
#include "bts.h"

void search(int ele) {
    Node* ptr = root;
    if (!root) {
        printf("The tree is empty!\n");
        return;
    }
    while(true) {
        if (ele == ptr->data) {
            printf("The element you are searching for is found in the tree\n");
            return;
        }
        else if (ele > ptr->data && ptr->rchild) {
            ptr = ptr->rchild;
            continue;
        }
        else if (ele < ptr->data && ptr->lchild) {
            ptr = ptr->lchild;
            continue;
        }
        else
            printf("The element you are searching for is not found in the tree.\n");
        return;
    }
}


