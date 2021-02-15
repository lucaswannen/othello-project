/**
 * \file jouerCoup.c
 * \brief Conception de jouerCoup
 * \author WANNENMACHER Lucas
 * \version 1.0
 * \date 01/12/2019
 */



#include "jouerCoup.h"



void jouerCoup(PL_Plateau *plateau, COUP_Coup coup, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2){
  PL_poserPion(plateau,COUP_obtenirPosition(coup),COUP_obtenirPion(coup));
  if (PION_obtenirCouleur(COUP_obtenirPion(coup))==NOIR){
    CPS_ajouter(coupsJ1, coup);
  }else{
    CPS_ajouter(coupsJ2, coup);
  }
  retournerPions(plateau,coup, coupsJ1, coupsJ2);
}
