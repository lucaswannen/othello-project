/**
 * \file retournerPions.h
 * \brief retournerPions fichier.h
 * \author WANNENMACHER Lucas
 * \version 1.0
 */

#include "Plateau.h"
#include "Coups.h"
#include <stdbool.h>

/**
 * \fn void retournerPionsDansUneDirection(PL_Plateau* plateau,COUP_Coup coup, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2,int abscisse_direction, int ordonnee_direction)
 * \brief retourne les pions qu'il faut retourner dans une direction
 * \author WANNENMACHER Lucas
 * \param plateau le plateau
 * \param coup le coup joué
 * \param coupsJ1 tous les pions du joueur 1
 * \param coupsJ2 tous les pions du joueur 2
 * \param abscisse_direction l'abscisse de la direction
 * \param ordonnee_direction l'ordonnée de la direction
 */
void retournerPionsDansUneDirection(PL_Plateau* plateau,COUP_Coup coup, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2,int abscisse_direction, int ordonnee_direction);

/**
 * \fn void retournerPions(PL_Plateau *plateau, COUP_Coup c, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2)
 * \brief procedure qui retourne tous les pions à retourner lorsqu'un coup est joué
 * \author WANNENMACHER Lucas
 * \param plateau le plateau
 * \param coup le coup joué
 * \param coupsJ1 tous les pions du joueur 1
 * \param coupsJ2 tous les pions du joueur 2
 */
void retournerPions(PL_Plateau *plateau, COUP_Coup c, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2);

