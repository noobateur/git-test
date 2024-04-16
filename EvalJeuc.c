#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define T_INVENTAIRE 9
#define T_OBJETS 7
#define T_TITRES 100
#define T_Num_Id 500
typedef struct eval EVAL;
typedef struct inventaire Inventaire ;
typedef struct pileObjets PileObjets ;


 char nomFichier[] = "EvalJeux.dat";


struct eval {

    int nbrAvis;
	char titre[T_TITRES];
	int TotNotes;

	};


    void RequeteJoueur(char nomFichier[]);
    void LireSauvegarde( char nomFichier[] );

void main(void) {


    RequeteJoueur(nomFichier);
    LireSauvegarde(nomFichier);
    
  }



void RequeteJoueur(char nomFichier[])
{

    FILE * fluxEval ;

    fopen_s(&fluxEval, nomFichier, "wb");

     EVAL eval = 
     {
        0,
        "",
        0,

    };

    printf(" Quel est le titre ? \n:  ");
    scanf("%s", &eval.titre);


    for
    ( int compteur = 0 ; compteur < strlen(eval.titre) ; compteur++){
        eval.titre[compteur] = toupper(eval.titre[compteur]);
        fwrite(&eval.titre[compteur],sizeof(char),1, fluxEval);
    }

    printf("%s \n", eval.titre);

    printf(" Entrez un nombre d'avis : \n "); 
    scanf_s("%d", &eval.nbrAvis, 1);

            while( eval.nbrAvis < 0){

                printf("Veuillez entrer un nombre correct ");
                scanf_s("%d", &eval.nbrAvis, 1);



            }

    printf(" Entrez le total des notes : \n "); 
    scanf_s("%d", &eval.TotNotes, 1);

            while( eval.TotNotes < 0){

                printf("Veuillez entrer un total correct correct ");
                scanf_s("%d", &eval.nbrAvis, 1);



            }

    fclose(fluxEval);

}
    void LireSauvegarde(char nomFichier[])
    {

        FILE * fluxEval;
        
            
        EVAL eval;

        fopen_s(&fluxEval, nomFichier, "rb");

        if(fluxEval == NULL)
        {

            printf("Erreur de lecture du fichier \n");
        }
        else
        {
            fread_s(&eval, sizeof(EVAL), sizeof(EVAL), 1 , fluxEval );

            printf(" Le titre : %s , Le nombre d'avis : %d , La cote total : %d ", eval.titre , eval.nbrAvis, eval.TotNotes);

            }
            printf(" Lu \n");
            fclose(fluxEval);

       


    }