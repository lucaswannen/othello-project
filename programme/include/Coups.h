/**
  * \file Coups.c
  * \brief TAD coups fichier.h
  * \author Maria Bianca Zugravu
  * \version 1.0
  */

#ifndef __COUPS__
#define __COUPS__

#include "Coup.h"

/**
* \def NB_CPS_MAX
* \brief defini le nombre de case max a 64
* \author Maria Bianca Zugravu
*/

#define NB_CPS_MAX 64

/**
* \struct CPS_Coups Coups.h "include/Coups.h"
* \brief la structure represente un ensemble de coup
* \author Maria Bianca Zugravu
*/

typedef struct CPS_Coups{
  COUP_Coup lesCoups[NB_CPS_MAX];
  unsigned int nbCoups;
}CPS_Coups;

/**
* \fn CPS_Coups CPS_coups()
* \brief renvoie un ensemble de coups vide
* \author Maria Bianca Zugravu
* \return CPS_Coups
*/

CPS_Coups CPS_coups();

/**
* \fn bool CPS_estCoupValide(CPS_Coups, COUP_Coup)
* \brief vérifie si un coup est valide et si il a ou non deja ete joue
* \author Maria Bianca Zugravu
* \return bool
*/

bool CPS_estCoupValide(CPS_Coups,COUP_Coup);

/**
* \fn COUP_Coup CPS_iemeCoup(CPS_Coups, unsigned int)
* \brief retourne le ieme coup d'un ensemble de coups
* \author Maria Bianca Zugravu
* \return COUP_Coup
*/

COUP_Coup CPS_iemeCoup(CPS_Coups, unsigned int);

/**
* \fn CPS_ajouter(CPS_Coups*, COUP_Coup)
* \brief ajoute un coup a un ensemble de coup
* \author Maria Bianca Zugravu
*/

void CPS_ajouter(CPS_Coups*, COUP_Coup);

/**
* \fn bool CPS_estPresent(CPS_Coups,COUP_Coup)
* \brief indique si un coup est present ou non dans un ensemble de coups
* \author Maria Bianca Zugravu
* \return bool
*/

bool CPS_estPresent(CPS_Coups,COUP_Coup);

/**
* \fn unsigned int CPS_nbCoups(CPS_Coups)
* \brief retourne le nombre de coups presents dans un ensemble de coups
* \author Maria Bianca Zugravu
* \return unsigned int
*/

unsigned int CPS_nbCoups(CPS_Coups);

/**
* \fn bool CPS_egal(CPS_Coups,CPS_Coups)
* \brief indique si deux ensembles de coups sont egaux ou non
* \author Maria Bianca Zugravu
* \return bool
*/

bool  CPS_egal(CPS_Coups,CPS_Coups);

/**
* \fn CPS_supprimer(CPS_Coups*, COUP_Coup)
* \brief supprime un coup d'un ensemble de coups
* \author Maria Bianca Zugravu
*/

void CPS_supprimer(CPS_Coups*, COUP_Coup);

#endif
