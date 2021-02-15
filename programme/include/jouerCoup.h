/**
 * \file jouerCoup.h
 * \brief Ijouercoup fichier.h
 * \author WANNENMACHER Lucas
 * \version 1.0
 */

#ifndef __JOUERCOUP__
#define __JOUERCOUP__

#include "Plateau.h"
#include "Coups.h"
#include "Position.h"
#include "Pion.h"
#include "Couleur.h"
#include "retournerPions.h"
#include <stdbool.h>

/**
 * \fn void jouerCoup(PL_Plateau *plateau, COUP_Coup c, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2)
 * \brief procedure qui permet de jouer un coup, c'est à dire de poser le pion, retourner les pions à retourner et modifier coupsJ1 et coupsJ2
 * \author WANNENMACHER Lucas
 * \param plateau le plateau
 * \param coupsJ1 les pions du joueur 1
 * \param coupsJ2 les pions du joueur 2
 */
void jouerCoup(PL_Plateau *plateau, COUP_Coup c, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2);

#endif
