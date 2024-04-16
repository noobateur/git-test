#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define T_NOM 100
#define NB_MOTS_CLES 3
#define T_MOT_CLE 25
typedef struct carte Carte ;


struct carte {
    char nom[T_NOM];
    int nbCasesHauteur;
    int nbCasesLargeur;
    bool officielle;
    char motsCles[NB_MOTS_CLES][T_MOT_CLE];
    Carte* pCarteSuivante;
};

void carteObtenue(Carte * pCarte);
void afficheCarte(Carte * pCarte);


void main(void) {
    Carte * pGrotte = (Carte *)malloc(sizeof(Carte));
    strcpy_s(pGrotte->nom, T_NOM, "Grottes pleines de rats");
    pGrotte->nbCasesHauteur = 15;
    pGrotte->nbCasesLargeur = 25; 
    pGrotte->officielle = false;
    strcpy_s(pGrotte->motsCles[0], T_MOT_CLE, "souterrain");
    strcpy_s(pGrotte->motsCles[1], T_MOT_CLE, "rats");
    strcpy_s(pGrotte->motsCles[2], T_MOT_CLE, "sombre");
    pGrotte->pCarteSuivante = NULL;

    free(pGrotte);
    carteObtenue(pGrotte);
    afficheCarte(pGrotte);
}

void carteObtenue(Carte * pCarte){
    char reponse;
    printf("Nom : ");
    gets_s(pCarte->nom, T_NOM);
    if (strcmp(pCarte->nom, "") != 0) {
        printf("Hauteur (en cases) : ");
        scanf_s("%d", &pCarte->nbCasesHauteur);
        printf("Largeur (en cases) : ");
        scanf_s("%d", &pCarte->nbCasesLargeur);
        getchar();
        printf("Officielle (O/N) : ");
        scanf_s("%c", &reponse, 1);
        pCarte->officielle = reponse == 'O';
        
        for (int i = 0; i < NB_MOTS_CLES; i++) {
            printf("Mot cle %d : ", i + 1);
            scanf_s("%s", pCarte->motsCles[i], T_MOT_CLE);
        }

        getchar();
        pCarte->pCarteSuivante = NULL;
        }
}

void afficheCarte(Carte * pCarte){
printf(" \n %s (%d x %d - %sofficielle)", 
pCarte->nom, 
pCarte->nbCasesHauteur, 
pCarte->nbCasesLargeur,
pCarte->officielle ? "" : "pas ");
    for(int i = 0; i < NB_MOTS_CLES; i++) {
        puts(pCarte->motsCles[i]);
    }
}