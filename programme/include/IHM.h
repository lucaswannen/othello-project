/**
  * \file IHM.h
  * \brief CIHM fichier.h
  * \version 1.0
  */

#include "Coups.h"
#include "Plateau.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void IHM_affichagePlateau(PL_Plateau, CPS_Coups, CPS_Coups);
  
COUP_Coup IHM_saisirCoup(CLR_Couleur);
