#include <stdio.h>
#define T_NOM 100
#define NB_MOTS_CLES 3
#define T_MOT_CLE 50


struct carte {

	char nom[T_NOM];
	int hauteur;
	int largeur;
	bool estOfficielle;
	char motCles[];



	};

	typedef struct carte Carte;

void main(void) {

	typedef struct carte Carte;

	struct carte uneGrotte = {
	"Grottes pleines de rats",
	15,
	25,
	false,
	{"souterrain", "rats", "sombre"}
	};

	Carte uneGrotte;


}
Carte carteObtenue ( void ){

	Carte carte ;
	char reponse;


	printf("Nom : "  );
	gets_s(carte.nom, T_NOM);
	printf("\n Hauteur :"  );
	scanf( " %d ", &carte.hauteur);
	printf("\n largeur :"  );
	scanf( " %d ", &carte.largeur);
	printf(" Officielle , oui ou non ? : ");
	scanf( "%c",reponse, 1 );
	carte.estOfficielle = reponse =='o';
	
	for(int i = 0; i < NB_MOTS_CLES; i++) {
		printf("Mot cle %d : ", i + 1);
		scanf_s("%s", carte.motCles[i], T_MOT_CLE);
	}

	return carte ; 

}