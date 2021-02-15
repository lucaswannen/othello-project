/**
  * \file coupsPossibles.h
  * \brief coupsPossibles fichier.h
  * \version 1.0
  */

#ifndef __COUPSPOSSIBLES__
#define __COUPSPOSSIBLES__
#endif

#include "Plateau.h"
#include "Coups.h"
#include <stdbool.h>



/**
 * \fn CPS_Coups coupsPossibles(PL_Plateau* plateau, CLR_Couleur Joueur)
 * \brief renvoie les coups possibles 
 * \param plateau le plateau 
 * \param Joueur la couleur du joueur qui joue
 * \return CPS_Coups les coups qu'il est possible de jouer
 */
CPS_Coups coupsPossibles(PL_Plateau* plateau, CLR_Couleur Joueur);
