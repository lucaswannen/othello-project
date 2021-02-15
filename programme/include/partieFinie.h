/**
 * \file partieFinie.h
 * \brief IPartieFinie fichier.h
 * \version 1.0
 */

#ifndef __PARTIEFINIE__
#define __PARTIEFINIE__

#include "Couleur.h"
#include "Plateau.h"
#include <stdbool.h>
#include "coupsPossibles.h"

typedef struct PF_retour{
  CLR_Couleur couleurGagnant;
  bool egalite;
  bool partieFinie;
  unsigned int scoreGagnant;
}PF_retour;

PF_retour partieFinie(PL_Plateau*,CPS_Coups,CPS_Coups,CLR_Couleur,CLR_Couleur);


#endif
