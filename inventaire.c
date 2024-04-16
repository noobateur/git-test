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
int checkReference(  int Id );
Inventaire ajouteObjet ( Inventaire invent , PileObjets pileObjets) ;
PileObjets MiseEnForme( void);
void AfficheInventaire( Inventaire invent);

 Objet objets[] = {
 { 117, "arc", 1000 },
 { 135, "epee courte", 1000 },
 { 57, "fleche", 25 },
 { 10, "torche", 500 },
 { 215, "pelle", 4000 },
 { 202, "grappin", 2000 },
 { 194, "seau", 1000 }

 };



void main(void) {


    /*
    PileObjets exemple = { 3 , objets[2]};

    invent = ajouteObjet( invent , exemple);

    printf(" Nom : %s \n, Id :  %d \n , poids : %d ", objets[1].nom , objets[1].numId , objets[1].poids );
        printf("Quantite :  %d \n", invent.Inventaire[3].quantite );

    
    
    int check = checkReference( 5 );*/

    /*AfficheInventaire(invent);*/
    

    Inventaire invent =  {
    
        {  
            {1 , objets[0]},
            { 7 , objets[3]},
            { 1 , objets[1]},
            { 32 , objets[2]}
        }
    };
    

    char reponse ;
    PileObjets pile ;

    printf( " Voici le menu . Que voulez vous faire ? \n (A) pour ajouter un objet \n (I) pour afficher l'inventaire \n (Q) pour quitter le menu  ");
    scanf_s("%c", &reponse, 1);

    
    while (reponse != 'q' ){


        while( reponse != 'i' && reponse != 'I' &&  reponse != 'A'&& reponse != 'a' && reponse != 'q' ){

            printf("Veuillez entrer une reponse correct :  ");
            scanf_s("%c", &reponse, 1);


        }

        if (reponse == 'i' ||reponse =='I'){

            AfficheInventaire(invent);
            printf("\n");


        }else if (reponse == 'a' || reponse == 'A'){

            
            pile = MiseEnForme();
            invent = ajouteObjet(invent , pile);
        }else{

            
        }
        

    
    printf( " Voici le menu  . Que voulez vous faire ? \n (A) pour ajouter un objet \n (I) pour afficher l'inventaire \n (Q) pour quitter le menu  ");
    getchar();
    scanf("%c", &reponse);
    


    }


    









}


    int checkReference( int Id ){


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
    

    PileObjets MiseEnForme( void ){
            
            int reference ;
            PileObjets pile ; 
            int quantite ;

            printf(" Entrez une référence : \n ");
            scanf_s("%d", &reference, 1);
            reference = checkReference(reference );

            while( reference == -1){

                printf("Veuillez entrer une référence correct ");
                scanf_s("%d", &reference, 1);
                reference = checkReference(reference );



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


