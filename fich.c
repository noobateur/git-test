
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define T_INVENTAIRE 9
#define T_OBJETS 7
#define T_NOM 20
#define T_Num_Id 500
typedef struct objet Objet;
typedef struct inventaire Inventaire ;
typedef struct pileObjets PileObjets ;


 char nomFichier[] = "inventaire.dat";


struct objet {

    int numId;
	char nom[T_NOM];
	int poids;

	};

struct pileObjets {

    int quantite ;
    Objet definition ;

};

struct inventaire{
   
    PileObjets Inventaire[T_INVENTAIRE];
};

int indiceObjet(int reponse ) ;
int checkReference(  int Id , Objet objets[]);
Inventaire ajouteObjet ( Inventaire invent , PileObjets pileObjets ) ;
PileObjets MiseEnForme( Objet objets[] );
void AfficheInventaire( Inventaire invent);
char choixObtenu();
void SauverInventaire( Inventaire invent, char nomFich[]);
Inventaire LireSauvegarde( char nomFich[]);




void main(void) {

        Objet objets[] = {
    { 117, "arc", 1000 },
    { 135, "epee courte", 1000 },
    { 57, "fleche", 25 },
    { 10, "torche", 500 },
    { 215, "pelle", 4000 },
    { 202, "grappin", 2000 },
    { 194, "seau", 1000 }

    };

    Inventaire invent = {
        .Inventaire = {0}
    };
    
   
    
    
    char reponse = choixObtenu();
    PileObjets pile ;





     while (reponse != 'Q' ){
  
        if (reponse == 'i' ||reponse =='I'){

            AfficheInventaire(invent);
            printf("\n");


        }else if (reponse == 'a' || reponse == 'A'){

            
            pile = MiseEnForme(objets);
            invent = ajouteObjet(invent , pile);
        }else if(reponse == 's' || reponse =='S'){

            SauverInventaire(invent , nomFichier);


        }else if(reponse == 'l' || reponse == 'L'){

           invent = LireSauvegarde(nomFichier);

        }

            
        
        

         reponse = choixObtenu();
         printf("%c",reponse);


    }


    
  }




    void SauverInventaire( Inventaire invent, char nomFich[]){

        FILE * fluxInventaire;

        fopen_s(&fluxInventaire, nomFich, "wb");

        if(fluxInventaire == NULL)
        {

            printf("Erreur du fichier");
        }else
        {

            for(int compteur = 0 ; compteur < T_INVENTAIRE ; compteur++ ){

                fwrite(&invent.Inventaire[compteur], sizeof(PileObjets), 1 , fluxInventaire );


            }
            printf(" Sauvegardé");
            fclose(fluxInventaire);


        }

    }

    

    Inventaire LireSauvegarde(char nomFich[])
    {

        FILE * fluxInventaire;
        Inventaire invent;

        fopen_s(&fluxInventaire, nomFich, "rb");

        if(fluxInventaire == NULL)
        {

            printf("Erreur de lecture du fichier \n");
        }
        else
        {
            fread_s(&invent, sizeof(Inventaire), sizeof(Inventaire), 1 , fluxInventaire );
            }
            printf(" Lu \n");
            fclose(fluxInventaire);

         return invent;


        }

    

    char choixObtenu(){
        char choix;
        printf("Menu :\n"

        "- A : ajouter des elements\n"
        "- I : afficher l'inventaire\n"
        "- S : sauver l'inventaire\n"
        "- Q : quitter\n"
        "-L : Lire fichier sauvegardée\n"
        ">>> choix :\n ");
        scanf_s("%c",&choix,1);
        getchar();

        while(choix != 'L' && choix != 'Q' && choix != 'A' && choix != 'I' &&  choix != 'C' &&  choix != 'S' ){
            printf("Choix impossible\n>>> choix : ");
            scanf_s("%c",&choix,1);
            
        }
        return choix; 
    }



    int checkReference( int Id , Objet objets[] ){


        int compteur = 0;
        int check= 0;


        while( compteur < T_OBJETS ){

            if(Id == objets[compteur].numId){

                 check = compteur;
            }
            compteur++;

        }   

        if ( check > 0 ){

            return check  ;

        }else{

            return -1 ;

        }
        

    }

    void AfficheInventaire( Inventaire invent){

        int compteur = 0;
        int total = 0; 

        while(invent.Inventaire[compteur].quantite != 0){

            printf("\t  %d x %s \n ", invent.Inventaire[compteur].quantite ,invent.Inventaire[compteur].definition.nom);
            total += invent.Inventaire[compteur].quantite * invent.Inventaire[compteur].definition.poids;
        

        compteur++;
        }

        printf(" Total : %d g", total);


    }
    

    PileObjets MiseEnForme( Objet objets[] ){
            
            int reference ;
            PileObjets pile ; 
            int quantite ;

            printf(" Entrez une référence : \n ");
            scanf_s("%d", &reference, 1);
            reference = checkReference(reference , objets);

            while( reference == -1){

                printf("Veuillez entrer une référence correct ");
                scanf_s("%d", &reference, 1);
                reference = checkReference(reference,objets );



            }

            printf(" Entrez une quantite : \n ");
            scanf_s("%d", &quantite, 1);

            while( quantite <= 0){

                printf("Veuillez entrer une quantite correct :  ");
                scanf_s("%d", &quantite, 1);


            }


            if( quantite >= 1 && reference <= T_Num_Id){

                pile.quantite = quantite;
                pile.definition.numId = reference;
                printf("%d", pile.definition.numId);
                        strcpy(pile.definition.nom , objets[pile.definition.numId].nom);
                        pile.definition.poids = objets[pile.definition.numId].poids;

                }
            
        
        
        return pile;
    }







Inventaire ajouteObjet ( Inventaire invent , PileObjets pileObjets) {

    int compteur = 0 ;
    int check = 0;

        while( compteur < T_INVENTAIRE && check >= 0 ){
            

            if(strcmp( invent.Inventaire[compteur].definition.nom , pileObjets.definition.nom  ) == 0){

                    invent.Inventaire[compteur].quantite += pileObjets.quantite ; 
                    
                    printf( " Objets ajoutes deja present \n");
                    check = -1  ;
                    
            }else if(invent.Inventaire[compteur].quantite == 0 ) {

                invent.Inventaire[compteur] = pileObjets;

                printf( " Objets ajoutes \n ");
                check = -1 ;

            
            }


            if( compteur == T_INVENTAIRE){

                 printf( " Inventaire plein \n ");

            }

            compteur++;

        }

       return invent ;

}
