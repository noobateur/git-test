#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define T_Choix 10


int choixPC(void);
void RequeteChoix( char reponse[T_Choix] );
int CheckChoix(char choix[]);



void main(void)
{

   int nb1 , nb2 ;
   printf(" Nombre 1 : \n ");
   scanf("%d", &nb1);
   printf(" \n  ");
   nb2 = nb1;
   printf(" %d , %d \n " , nb1 , nb2);



    int* p1 , * p2 ;
    p1 = &nb1; 
    p2 = p1 ;

   printf(" Pointeur  1 : %d \n pointeur 2  : %d   \n", *p1 , *p2 ); 
   printf(" Pointeur  1 : %p \n pointeur 2  : %p   \n", p1 , p2 );
   
   printf(" Nombre Pointeur 2 :  ");
   scanf("%d", p2);
   printf(" \n  ");
   printf(" Pointeur  1 : %d \n pointeur 2  : %d   ", *p1 , *p2 );



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




void RequeteChoix(   char reponse[T_Choix] )
{



}

