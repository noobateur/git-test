#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define T_Choix 10


int choixPC(void);
void RequeteChoix( char reponse[T_Choix] );
int CheckChoix(char choix[]);



void main(void)
{

    char decision[T_Choix];
    RequeteChoix( decision);

    int personne = CheckChoix(decision); 
    int bot = choixPC();


    if( bot == personne ){

        printf(" Pas mal , égalité");


    }else if(bot == 0 && personne == 1 ){

        printf(" Vous avez gagné"  );

    }else if(bot == 1 && personne == 0 ){

        printf(" Vous avez perdu"  );

    }else if(bot == 1 && personne == 2 ){

        printf(" Vous avez gagné"  );

    }else if(bot == 2 && personne == 1 ){

        printf(" Vous avez perdu"  );

    }else if(bot == 0 && personne == 2 ){

        printf(" Vous avez perdu"  );

    }else if(bot == 2 && personne == 0 ){

        printf(" Vous avez gagne"  );

    }else{

        printf(" erreur");
        printf("%d \n ", bot);
        printf("%d",personne);
    }




}



int CheckChoix(char choix[])
{

    char pierre[] = "PIERRE";
    char papier[] = "PAPIER";
    char ciseaux[] = "CISEAUX";

    for( int compteur = 0 ; compteur < strlen(choix) ; compteur++){
        choix[compteur] = toupper(choix[compteur]);
    }

    if( strcmp(choix,pierre) == 0 )
    {

        return 0;

    }else if(strcmp(choix,papier) == 0)
    {

        return 1;

    }else if(strcmp(choix,ciseaux) == 0 )
    {

        return 2;
    }else
    {
    
        return -1;
    } 
 


}




int choixPC(void){


    int choixPC = rand() % 3 ; 

    
    return choixPC;

}




void RequeteChoix(   char reponse[T_Choix] )
{


 printf(" Quel choix , faites vous ? \n  pour Pierre  \n  Papier \n Ciseaux \n :  ");
 scanf("%s", reponse);
 int validation = CheckChoix( reponse);

 while( validation == -1)
 {

    printf("Veuillez entrer un choix correct ");
    scanf("%s", reponse);
    validation = CheckChoix(reponse );



 }


}

