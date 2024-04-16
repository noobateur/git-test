#include <stdio.h>
#define FICHIER_CARTES "cartes.dat"

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
