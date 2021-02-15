/**
  * \file Pion.h
  * \brief TAD pion fichier.h
  * \author Maria Bianca Zugravu
  * \version 1.0
  */

#ifndef __PION__
#define __PION__

#include "Couleur.h"

/**
* \struct PION_Pion Pion.h "include/Pion.h"
* \brief la structure representant un pion
* \author Maria Bianca Zugravu
*/

typedef struct PION_Pion{
  CLR_Couleur couleur;
} PION_Pion;

/**
* \fn PION_Pion PION_pion(CLR_Couleur)
* \brief retourne un pion de la couleur souhaitee
* \author Maria Bianca Zugravu
* \return PION_Pion
*/

PION_Pion PION_pion(CLR_Couleur);

/**
* \fn CLR_Couleur PION_obtenirCouleur(PION_Pion)
* \brief retourne la couleur d'un pion
* \author Maria Bianca Zugravu
* \return CLR_Couleur
*/

CLR_Couleur PION_obtenirCouleur(PION_Pion);

/**
* \fn PION_retournerPion(PION_Pion)
* \brief fais passer la couleur d'un pion de blanc a noir ou l'inverse
* \author Maria Bianca Zugravu
*/

void PION_retournerPion(PION_Pion*);

/**
* \fn bool PION_sontEgaux(PION_Pion, PION_Pion)
* \brief indique si deux pions sont égaux ou non
* \author Maria Bianca Zugravu
* \return bool
*/

bool PION_sontEgaux(PION_Pion, PION_Pion);

#endif
