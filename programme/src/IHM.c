/**
 * \file IHM.c
 * \brief fonction IHM
 * \version 1.0
 */

#include "IHM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IHM_affichagePlateau(PL_Plateau plateau, CPS_Coups coupsJ1, CPS_Coups coupsJ2){
  printf("\n");
  int i, j;
  printf("   a b c d e f g h [BLANCS=%d NOIRS=%d] \n", CPS_nbCoups(coupsJ2), CPS_nbCoups(coupsJ1));
  for(i=1;i<=LARGEUR;i++){
    printf("%d ",i);
    for(j=1;j<=HAUTEUR;j++){
      if (PL_caseVide(plateau,POS_position(i,j)))
	printf(" .");
      else{
	if (PION_obtenirCouleur(PL_obtenirPion(plateau,POS_position(i,j)))==NOIR)
	  printf(" x");
	else
	  printf(" o");
      }
    }
    printf("\n");
  }
}

COUP_Coup IHM_saisirCoup(CLR_Couleur couleurJoueur){
  COUP_Coup leCoup;
  char coup[5];
  while(!((1<=coup[1]-'0') && (coup[1]-'0'<=8) && (1<=(int)coup[0]-96) && ((int)coup[0]-96<=8) && (strlen(coup)==4))){
    printf("\n \n Veuillez entrer un coup (une lettre entre a et h, puis un chiffre entre 1 et 8 et enfin le caractère de retour '\\n'. Voici un exemple pour le coup e5 : 'e5\\n' ) : \n");
    fgets(coup,5*sizeof(char),stdin);
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
  }
  leCoup = COUP_coup(PION_pion(couleurJoueur),POS_position(coup[1]-'0',(int)coup[0]-96));
  return leCoup;
}
