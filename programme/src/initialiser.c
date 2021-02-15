/**
 * \file initialiser.c
 * \brief fonction initialiser
 * \version 1.0
 */

#include "initialiser.h"
#include "Plateau.h"
#include <stdlib.h>
#include "Position.h"
#include <stdbool.h>

void initialiser(PL_Plateau* plateau, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2){
  PL_initialiser(plateau);
  PL_fixerPionDansCase(plateau, POS_position(4,4), PION_pion(BLANC));
  CPS_ajouter(coupsJ2, COUP_coup(PION_pion(BLANC), POS_position(4,4)));
  PL_fixerCaseAVide(plateau,POS_position(4,4),false);
  PL_fixerPionDansCase(plateau, POS_position(5,5), PION_pion(BLANC));
  CPS_ajouter(coupsJ2, COUP_coup(PION_pion(BLANC), POS_position(5,5)));
  PL_fixerCaseAVide(plateau,POS_position(5,5),false);
  PL_fixerPionDansCase(plateau, POS_position(4,5), PION_pion(NOIR));
  CPS_ajouter(coupsJ1, COUP_coup(PION_pion(NOIR), POS_position(4,5)));
  PL_fixerCaseAVide(plateau,POS_position(4,5),false);
  PL_fixerPionDansCase(plateau, POS_position(5,4), PION_pion(NOIR));
  CPS_ajouter(coupsJ1, COUP_coup(PION_pion(NOIR), POS_position(5,4)));
  PL_fixerCaseAVide(plateau,POS_position(5,4),false);
}
