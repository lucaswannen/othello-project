/**
 * \file obtenirCoupIA
 * \brief obtenirCoupIA fichier.h
 * \version 1.0
 */

#ifndef __OBTENIRCOUPIA__
#define __OBTENIRCOUPIA__

#include "Plateau.h"
#include "Coups.h"
#include "coupsPossibles.h"
#include "partieFinie.h"
#include "jouerCoup.h"
/**
 * \fn int evaluer(PL_Plateau, CLR_Couleur)
 * \brief attribue à chaque case une valeur signifiant l'intérêt pour l'IA de jouer sur cette case
 */
int evaluer(PL_Plateau, CLR_Couleur);

/**
 * \fn int scoreDUnCoup(PL_Plateau*, COUP_Coup,CLR_Couleur,CPS_Coups, CPS_Coups, unsigned int, int, int)
 * \brief revoie si l'on joue un certain coup
 * \return int le resultat de alpha beta
 */
int scoreDUnCoup(PL_Plateau*, COUP_Coup,CLR_Couleur,CPS_Coups, CPS_Coups, unsigned int, int, int);

/**
 * \fn int alphaBeta(PL_Plateau*, CLR_Couleur, CLR_Couleur,CPS_Coups, CPS_Coups, unsigned int, int, int)
 * \brief cette fonction contient l'algorithme aplha-bêta
 * \return int le resultat de alpha beta
 */
int alphaBeta(PL_Plateau*, CLR_Couleur, CLR_Couleur,CPS_Coups, CPS_Coups, unsigned int, int, int);

/**
 * \fn COUP_Coup obtenirCoupIA(PL_Plateau*, CLR_Couleur, CPS_Coups, CPS_Coups)
 * \brief fonction qui obtient le coup de l'IA
 */
COUP_Coup obtenirCoupIA(PL_Plateau*, CLR_Couleur, CPS_Coups, CPS_Coups);


#endif
