#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define MAX_TERMS 100

typedef struct {
    int coeff;
    int exp;
} Term;

typedef struct {
    Term terms[MAX_TERMS];
    int n;
} Polynomial;

void inputPolynomial(Polynomial *p, int polyNumb);
void displayPolynomial(Polynomial p);
Polynomial addPolynomials(Polynomial p1, Polynomial p2);
void sortPolynomial(Polynomial *p);

#endif
