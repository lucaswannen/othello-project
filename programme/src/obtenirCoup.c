/**
 * \file obtenirCoup.c
 * \brief fonction obtenirCoup
 * \version 1.0
 */

#include "obtenirCoup.h"
#include <string.h>

COUP_Coup obtenirCoup(PL_Plateau* plateau, CLR_Couleur joueurCourant,char* mode,CPS_Coups cpsJ1, CPS_Coups cpsJ2){
  COUP_Coup coup;
  char* mode1 = "standard";
  CLR_Couleur noir = NOIR;
  if (strcmp(mode,mode1)==0){
    if (CLR_sontEgales(noir,joueurCourant)){
      coup = obtenirCoupJoueur(plateau,joueurCourant);
    }else{
      coup = obtenirCoupIA(plateau,joueurCourant,cpsJ1,cpsJ2);
      printf("Coup IA (%x,%x) :", POS_obtenirAbcisse(COUP_obtenirPosition(coup)), POS_obtenirOrdonnee(COUP_obtenirPosition(coup)));
    }
  }
  else{
    coup = obtenirCoupIA(plateau,joueurCourant,cpsJ1,cpsJ2);
  }
  return coup;
}
