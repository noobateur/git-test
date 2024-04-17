#include <stdio.h>
#include <ctype.h> 
#include <string.h>


char MenuUtilisateur(void);


void main(void)
{

   



}


char MenuUtilisateur(void){

    char reponse ;

    printf(" Dameoiseaux/damoiselles  \n Que voulez vous faire ? \n\n Taper (N) pour lancer une nouvelle partie de pendu\n Taper (Q) pour quitter ce jeu \n Taper (R) pour voir la reine d'Angleterre faire du Breakdance ");
    scanf( " %c ", &reponse);



    return reponse ;

}



char ChoixJoueur(void){

    char reponse ;

    printf(" Choissisez bien , quel lettre est la bonne ? ");
    scanf( " %c ", &reponse);



    return reponse ;


}


