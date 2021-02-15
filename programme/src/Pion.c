/**
 * \file Pion.c
 * \brief Implementation du TAD Pion
 * \author Maria Bianca Zugravu
 * \version 1.0
 */

#include <stdlib.h>
#include "Pion.h"

PION_Pion PION_pion(CLR_Couleur couleur) {
  PION_Pion pion;
  pion.couleur = couleur;
  return pion;

}

CLR_Couleur PION_obtenirCouleur(PION_Pion pion){
  return pion.couleur;
}

void PION_retournerPion(PION_Pion* pion){
  pion ->couleur= CLR_changerCouleur(PION_obtenirCouleur(*pion));
}

bool PION_sontEgaux(PION_Pion pion1, PION_Pion pion2){
  return CLR_sontEgales(pion1.couleur,pion2.couleur);
}
