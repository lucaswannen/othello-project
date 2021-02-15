/**
  * \file Plateau.h
  * \brief TAD Plateau fichier.h
  * \author Maria Bianca Zugravu
  * \version 1.0
  */

#ifndef __PLATEAU__
#define __PLATEAU__

#include "Pion.h"
#include "Position.h"

/**
* \def LARGEUR 8
* \brief initialise le nombre de colonnes du plateau a 8
*/

#define LARGEUR 8

/**
* \def HAUTEUR 8
* \brief initialise le nombre de lignes du plateau a 8
*/

#define HAUTEUR 8

/**
* \def NB_CASES_MAX 64
* \brief initialise le nombre de cases du plateau a 64
*/

#define NB_CASES_MAX 64

/**
* \struct PL_Case Plateau.h "include/Plateau.h"
* \brief la structure qui represente une case
*/

typedef struct PL_Case{
  PION_Pion pion;
  bool caseVide;
}PL_Case;

/**
* \typedef PL_Case PL_Plateau[LARGEUR][HAUTEUR]
* \brief la structure qui represente un plateau avec la taille HAUTEUR * LARGEUR
*/

typedef PL_Case PL_Plateau[LARGEUR][HAUTEUR];

/**
* \fn void PL_fixerCaseAVide(PL_Plateau*, POS_Position, bool)
* \brief fixe l'etat d'une case a vide
*/

void PL_fixerCaseAVide(PL_Plateau*, POS_Position, bool);

/**
* \fn void PL_fixerPionDansCase(PL_Plateau*, POS_Position, PION_Pion)
* \brief fixe un pion dans une case a une position donnee
*/

void PL_fixerPionDansCase(PL_Plateau*, POS_Position, PION_Pion);

/**
* \fn void PL_initialiser(PL_Plateau*)
* \brief initialise l'ensemble des cases d'un plateau a vide
*/

void PL_initialiser(PL_Plateau*);

/**
* \fn bool PL_caseVide(PL_Plateau, POS_Position)
* \brief indique si une certaine case est vide ou non
* \return bool
*/

bool PL_caseVide(PL_Plateau, POS_Position);

/**
* \fn bool PL_estRempli(PL_Plateau)
* \brief indique si un plateau est rempli ou non
* \return bool
*/

bool PL_estRempli(PL_Plateau);

/**
* \fn PION_Pion PL_obtenirPion(PL_Plateau, POS_Position)
* \brief retourne le pion present a une certaine position
* \return PION_Pion
*/

PION_Pion PL_obtenirPion(PL_Plateau, POS_Position);

/**
* \fn void PL_poserPion(PL_Plateau*,POS_Position,PION_Pion)
* \brief pose le pion indique a la position indique sur le plateau
*/

void PL_poserPion(PL_Plateau*,POS_Position,PION_Pion);

/**
* \fn void PL_enleverPion(PL_Plateau*,POS_Position)
* \brief enleve le pion present sur le plateau a une certaine position
*/

void PL_enleverPion(PL_Plateau*,POS_Position);

/**
* \fn void PL_retournerPion(PL_Plateau*,POS_Position)
* \brief change la couleur d'un pion a la position indiquee de blanc a noir ou l'inverse
*/

void PL_retournerPion(PL_Plateau*,POS_Position);

/**
* \fn bool PL_sontCasesEgales(PL_Plateau,PL_Plateau,POS_Position)
* \brief indique si deux cases a une position donnee sont egales sur deux plateaux differents
* \return bool
*/

bool PL_sontCasesEgales(PL_Plateau,PL_Plateau,POS_Position);

/**
* \fn bool PL_sontPlateuxEgaux(PL_Plateau,PL_Plateau)
* \brief indique si deux plateaux sont egaux ou non
* \return bool
*/

bool PL_sontPlateuxEgaux(PL_Plateau,PL_Plateau);

/**
* \fn void PL_copier(PL_Plateau*,PL_Plateau)
* \brief retourne la copie d'un plateau deja existant
*/

void PL_copier(PL_Plateau*,PL_Plateau);

#endif
