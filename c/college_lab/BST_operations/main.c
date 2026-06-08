#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bts.h"

int main() {
    int ch, ele;

    printf("Your choices;\n\t1.insert\n\t2.search\n\t3.delete\n\t4.display\n\t5.exit\n");
    while(true) {
        printf("Enter you choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert(ele);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &ele);
                search(ele);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &ele);
                root = delete(root, ele);
            case 4:
                display(root);
                printf("\n");
                break;
            case 5:
                printf("program terminating.");
                exit(0);
            default:
                printf("invalid choice.");
                break;
        }
    }
}
