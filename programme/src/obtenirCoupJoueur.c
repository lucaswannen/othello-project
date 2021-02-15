/**
 * \file obtenirCoupJoueur.h
 * \brief fonction obtenirCoupJoueur
 * \version 1.0
 */

#include "obtenirCoupJoueur.h"
#include "Couleur.h"
#include <stdbool.h>

COUP_Coup obtenirCoupJoueur(PL_Plateau* plateau, CLR_Couleur joueurCourant){
  bool estCoupValide = false;
  COUP_Coup coup;
  while (!estCoupValide){
    coup = IHM_saisirCoup(joueurCourant);
    estCoupValide = CPS_estPresent(coupsPossibles(plateau,joueurCourant),coup);
  }
  return coup;
}
