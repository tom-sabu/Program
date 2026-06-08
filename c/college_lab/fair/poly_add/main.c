#include <stdio.h>
#include <string.h>

struct poly {
    int coeff[101];
    char name[20];
};

void read_poly(struct poly *p, int n) {
    printf("Enter how many terms polynomial %s will have: ", p->name);
    int terms;
    scanf("%d", &terms);

    printf("Enter %d terms for polynomial %s (exponent coefficient):\n", terms, p->name);
    for (int i = 0; i < terms; i++) {
        int exp, coeff;
        scanf("%d %d", &exp, &coeff);

        if (exp < 0 || exp > 100) {
            printf("The exponent must be within the range 0-100\n");
            i--;
            continue;
        }

        p->coeff[exp] += coeff;
    }
    printf("\n");
}

void disp_poly(struct poly *p) {
    printf("Polynomial %s: ", p->name);
    int first_term = 1;

    for (int i = 100; i >= 0; i--) {
        if (p->coeff[i] == 0) continue;

        if (!first_term) {
            printf(" + ");
        }

        if (i == 0) {
            printf("%d", p->coeff[i]);
        } else if (i == 1) {
            printf("%dx", p->coeff[i]);
        } else {
            printf("%dx^%d", p->coeff[i], i);
        }

        first_term = 0;
    }

    if (first_term) {
        printf("0");
    }

    printf("\n");
}

void add_poly(struct poly *p1, struct poly *p2, struct poly *p3) {
    for (int i = 0; i <= 100; i++) {
        p3->coeff[i] = p1->coeff[i] + p2->coeff[i];
    }
}

int main() {
    struct poly p1, p2, p3;

    memset(p1.coeff, 0, sizeof(p1.coeff));
    memset(p2.coeff, 0, sizeof(p2.coeff));
    memset(p3.coeff, 0, sizeof(p3.coeff));

    strcpy(p1.name, "1");
    strcpy(p2.name, "2");
    strcpy(p3.name, "Result");

    printf("\n=== Polynomial Addition Program ===\n\n");

    read_poly(&p1, 1);
    read_poly(&p2, 2);

    add_poly(&p1, &p2, &p3);

    printf("\n--- Output ---\n");
    disp_poly(&p1);
    disp_poly(&p2);
    disp_poly(&p3);

    return 0;
}
