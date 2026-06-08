#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main(void)
{
    Polynomial poly1, poly2, result;

    printf("== Polynomial addition program ==\n");

    inputPolynomial(&poly1, 1);
    inputPolynomial(&poly2, 2);

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);

    printf("\nSecond Polynomial: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial: ");
    displayPolynomial(result);

    return EXIT_SUCCESS;
}


