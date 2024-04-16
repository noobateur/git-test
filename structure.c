#include <stdio.h>
#include <stdbool.h>
#define T_NOM 100
#define NB_MOTS_CLES 3
#define T_MOT_CLE 50
#define NB_Cartes 4
#define FICHIER_CARTES "cartes.dat"
typedef struct carte Carte;

struct carte {

	char nom[T_NOM];
	int hauteur;
	int largeur;
	bool estOfficielle;
	char motCles[T_MOT_CLE];



	};

Carte carteObtenue ( void );
void sauverCartes(Carte cartes[], int nbCartes) ;
int lireCartes(Carte cartes[]);



void main(void) {

	

	Carte uneGrotte ;
	Carte cartes[NB_Cartes] ;

	uneGrotte = carteObtenue();
    printf("%d \n ", uneGrotte.hauteur );
    printf("%d \n  " , uneGrotte.largeur );
    printf("%s \n", uneGrotte.nom  );
    
    sauverCartes(  cartes, 3);
    lireCartes(  cartes);


}

Carte carteObtenue ( void ){

	Carte carte ;
	char reponse;


	printf("Nom : "  );
	gets_s(carte.nom, T_NOM);
	printf("\n Hauteur :"  );
	scanf( "%d", &carte.hauteur);
	printf("\n largeur :"  );
	scanf( "%d", &carte.largeur);
	printf(" \n Officielle , oui ou non ? : ");
    getchar();
	scanf_s( "%c",&reponse, 1 );
	carte.estOfficielle = reponse =='o';
	
	for(int i = 0; i < NB_MOTS_CLES; i++) {
		printf("\n Mot cle %d : ", i + 1);
		scanf_s("%s", &carte.motCles[i], T_MOT_CLE);
	}

	return carte ; 

}



void sauverCartes(Carte cartes[], int nbCartes) {
	FILE * fluxCartes; //adresse du flux

	fopen_s(&fluxCartes, FICHIER_CARTES, "wb");

	if (fluxCartes == NULL) // vérifier que l’overture s’est bien passée
		printf("Erreur lors de l'ouverture du fichier.\n");
	else {
	
		for (int iCarte = 0; iCarte < nbCartes; iCarte++) {
	// on écrit chaque carte (=structure//enregistrement) dans le fichier
			fwrite(&cartes[iCarte], sizeof(Carte), 1, fluxCartes);
		} 
		fclose(fluxCartes); // fermeture
	}
}

int lireCartes(Carte cartes[]) {
 FILE * fluxCartes;
 Carte carte;
 int iCarte = 0;

 fopen_s(&fluxCartes, FICHIER_CARTES, "rb");
 if (fluxCartes == NULL) // vérifier que l’ouverture s’est bien passée
 printf("Erreur lors de l'ouverture du fichier.\n");
 else { 
// boucle sur chaque enregistrement lu (boucle d’obtention)
 fread_s(&carte, sizeof(Carte), sizeof(Carte), 1, fluxCartes);
 while (!feof(fluxCartes)) {
 cartes[iCarte] = carte;
 iCarte++;
 fread_s(&carte, sizeof(Carte), sizeof(Carte), 1, fluxCartes);
 } 
 fclose(fluxCartes); // fermeture
 }
 return iCarte;
}
