/**
 * \file Coup.c
 * \brief Implementation du TAD Coup
 * \author Maria Bianca Zugravu
 * \version 1.0
 */

#include "Coup.h"


COUP_Coup COUP_coup(PION_Pion pion, POS_Position pos){
  COUP_Coup coup;
  coup.pion = pion;
  coup.position = pos;
  return coup;
}

PION_Pion COUP_obtenirPion(COUP_Coup coup){
  return coup.pion;
}

POS_Position COUP_obtenirPosition(COUP_Coup coup){
  return coup.position;
}

bool COUP_estValide(COUP_Coup coup){
  /*fonction qui vérifie si le coup à placer ne sort pas des limites de la grille
   */
  return ((1<=POS_obtenirAbcisse(coup.position)) && (POS_obtenirOrdonnee(coup.position)<=8));
}

bool COUP_sontEgaux(COUP_Coup coup1, COUP_Coup coup2){
  return ((PION_sontEgaux(coup1.pion, coup2.pion))&&(POS_sontEgales(coup1.position,coup2.position)));

}
