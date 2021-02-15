/**
  * \file Couleur.c
  * \brief Conception du TAD Couleur
  * \author Maria Bianca Zugravu
  * \version 1.0
  * \date 01/12/2019
  */

#include "Couleur.h"

CLR_Couleur CLR_changerCouleur(CLR_Couleur couleur){
  if (couleur==BLANC)
    return NOIR;
  else
    return BLANC;
}

bool CLR_sontEgales(CLR_Couleur couleur1, CLR_Couleur couleur2){
  return (couleur1==couleur2);
}
