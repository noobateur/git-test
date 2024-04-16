#include <stdio.h>

void main(void) {
 int nbTorchesSac = 20;
 int * pNbTorchesSac = &nbTorchesSac;
 
printf("Valeur de nbTorchesSac %d (%p)\n", nbTorchesSac, &nbTorchesSac);
printf("Valeur de pNbTorchesSac %p (%p)\n", pNbTorchesSac, &pNbTorchesSac);


int caPersos[3] = {17, 16, 22};

int * pCaPerso = caPersos;

    for(int i = 0; i < 3; i++) {
    
        printf("caPersos[%d] vaut %d et est a l'adresse %p.\n", i, *pCaPerso, pCaPerso);
        pCaPerso++;
    }
}