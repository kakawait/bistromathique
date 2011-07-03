#ifndef ARITHMETIQUE_H_INCLUDED
#define ARITHMETIQUE_H_INCLUDED
#include "liste.h"
#define BASE 10

BIGINT addition(BIGINT, BIGINT);
BIGINT soustraction(BIGINT, BIGINT);
BIGINT multiplication(BIGINT, BIGINT);
BIGINT multiplicationBasique(BIGINT, BIGINT);
BIGINT multiplicationKaratsuba(BIGINT, BIGINT);
BIGINT divisionScolaire(BIGINT, BIGINT);
BIGINT divisionPar2(BIGINT);
BIGINT racine_carree(BIGINT);
BIGINT puissanceBasique(BIGINT, int);
BIGINT puissanceDC(BIGINT, int unsigned);
BIGINT factorielle(unsigned int);
BIGINT left_shift(BIGINT, unsigned int);
BIGINT right_shift(BIGINT, unsigned int);

#endif // ARITHMETIQUE_H_INCLUDED
