#include <stdio.h>

int main() {
    const int MAX_SIZE = 100;
    int A[MAX_SIZE];
    int n = 0;
    int i;
    int choice;
    int x;
    int p;

    printf("Enter the initial number of elements (n): ");
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE) {
        printf("Invalid initial size. Setting size to 0.\n");
        n = 0;
    }

    if (n > 0) {
        printf("Enter %d array elements:\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
    }
    printf("\n--- ARRAY OPERATIONS MENU ---\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. Search element\n");
    printf("4. Display array\n");
    printf("5. Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter element to insert (x): ");
                scanf("%d", &x);
                printf("Enter position to insert at (p): ");
                scanf("%d", &p);

                if (p < 1 || p > n + 1) {
                    printf("Invalid position!\n");
                }
                else if (n >= MAX_SIZE) {
                    printf("Array Overflow! Cannot insert element.\n");
                }
                else {
                    for (i = n; i >= p; i--) {
                        A[i] = A[i - 1];
                    }

                    A[p - 1] = x;

                    n++;
                    printf("Element Inserted.\n");
                }
                break;

            case 2:
                printf("Enter position to delete from (p): ");
                scanf("%d", &p);

                if (p < 1 || p > n) {
                    printf("Invalid Position!\n");
                }
                else if (n == 0) {
                    printf("Array Underflow! Cannot delete element.\n");
                }
                else {
                    printf("Element %d deleted.\n", A[p - 1]);

                    for (i = p - 1; i < n - 1; i++) {
                        A[i] = A[i + 1];
                    }

                    n--;
                }
                break;

            case 3:
                printf("Enter element to search for (x): ");
                scanf("%d", &x);
                int found = 0;
                for (i = 0; i < n; i++) {
                    if (A[i] == x) {
                        printf("Element found at position %d\n", (i + 1));
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Element Not Found.\n");
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements are:\n");
                    for (i = 0; i < n; i++) {
                        printf("%d ", A[i]);
                    }
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
