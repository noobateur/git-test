#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define NB_REELS 25



void main(void){

    double centiemes[NB_REELS];
    int i;
    for(i = 0 ; i < NB_REELS ; i++){
    
    centiemes[i] = (double)i/100;

    }

    double * pCentieme ;
    pCentieme = &centiemes[2];
    printf( "%lf \n " , *pCentieme );
    pCentieme += 3  ;
    *pCentieme += 5 ;
    printf( "%lf" , *pCentieme );


    char * pSection ;
    int nbCaract ;
    printf( "Combien de caractères : ");
    scanf( "%d", &nbCaract);
    pSection = (void *) malloc(sizeof(char )* nbCaract);
    printf( "Votre Hero : ");
    gets( pSection);
    getchar();
    printf(" \n votre hero est %s ", pSection);


}