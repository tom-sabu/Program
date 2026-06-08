#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>

void inputPolynomial(Polynomial *p, int polyNum) {
  printf("Enter the number of terms in polynomial %d: ", polyNum);
  scanf("%d", &p->n);

  if (p->n > MAX_TERMS) {
    printf("Error: Maximum %d is allowed!!\n", MAX_TERMS);
    p->n = MAX_TERMS;
  }

  printf("Enter terms (Coefficient and Exponent):\n");
  for (int i = 0; i < p->n; i++) {
    printf("Term %d - Coefficient: \n", i + 1);
    scanf("%d", &p->terms[i].coeff);
    printf("Term %d - Exponent: \n", i + 1);
    scanf("%d", &p->terms[i].exp);
  }

  sortPolynomial(p);
}

void displayPolynomial(Polynomial p) {
  if (p.n == 0) {
    printf("0\n");
    return;
  }
  for (int i = 0; i < p.n; i++) {
    if (i == 0) {
      if (p.terms[i].coeff < 0)
        printf("-");
      if (abs(p.terms[i].coeff) != 1 || p.terms[i].exp == 0)
        printf("%d", abs(p.terms[i].coeff));
    } else {
      if (p.terms[i].coeff > 0)
        printf(" + ");
      else
        printf(" - ");

      if (abs(p.terms[i].coeff) != 1 || p.terms[i].exp == 0)
        printf("%d", abs(p.terms[i].coeff));
    }

    if (p.terms[i].exp > 1)
      printf("x^%d", p.terms[i].exp);
    else
      printf("x");
  }
  printf("\n");
}

Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
  Polynomial result;
  result.n = 0;
  int i = 0, j = 0;

  while (i < p1.n && j < p2.n) {
    if (p1.terms[i].exp > p2.terms[j].exp) {
      result.terms[result.n++] = p1.terms[i++];
    } else if (p1.terms[i].exp < p2.terms[i].exp) {
      result.terms[result.n++] = p2.terms[j++];
    } else {
      int sum = p1.terms[i].coeff + p2.terms[j].coeff;
      if (sum != 0) {
        result.terms[result.n].coeff = sum;
        result.terms[result.n].exp = p1.terms[i].exp;
        result.n++;
      }
      i++;
      j++;
    }
  }

  while (i < p1.n) {
    result.terms[result.n++] = p1.terms[i++];
  }

  while (i < p1.n) {
    result.terms[result.n++] = p1.terms[i++];
  }

  while (j < p2.n) {
    result.terms[result.n++] = p2.terms[j++];
  }

  return result;
}

void sortPolynomial(Polynomial *p) {
    for (int i = 0; i < p->n - 1; i++) {
        for (int j = 0; j < p->n - i - 1; j++) {
            if (p->terms[j].exp < p->terms[j + 1].exp) {
                Term temp = p->terms[j];
                p->terms[j] = p->terms[j + 1];
                p->terms[j + 1] = temp;
            }
        }
    }
}
