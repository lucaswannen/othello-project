/**
 * \file obtenirCoup.h
 * \brief obtenirCoup fichier.h
 * \version 1.0
 */

#ifndef __OBTENIRCOUP__
#define __OBTENIRCOUP__


#include "Plateau.h"
#include "Coup.h"
#include "Position.h"
#include "Pion.h"
#include "obtenirCoupJoueur.h"
#include "obtenirCoupIA.h"
#include <stdbool.h>
/**
 * \fn COUP_Coup obtenirCoup(PL_Plateau*,CLR_Couleur, char*,CPS_Coups,CPS_Coups)
 * \brief fonction pour obtenir les coups
 * \return COUP_Coup le coup choisi
 */
COUP_Coup obtenirCoup(PL_Plateau*,CLR_Couleur, char*,CPS_Coups,CPS_Coups);

#endif
