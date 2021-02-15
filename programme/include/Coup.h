/**
  * \file Coup.c
  * \brief TAD Coup
  * \author Maria Biancia Zugravu
  * \version 1.0
  * \date 01/12/2019
  */

#ifndef __COUP__
#define __COUP__

#include "Pion.h"
#include "Position.h"

/**
* \struct CP_Coup.h "include/Coup.h"
* \brief structure representant un coup à partir d'un pion et d'une position
*/

typedef struct COUP_Coup{
  PION_Pion pion;
  POS_Position position;
}COUP_Coup;

/**
* \fn CP_Coup CP_coup(PION_Pion pion, POS_Position pos)
* \brief renvoie le coup compose du pion et de la position
* \author Maria Biancia Zugravu
* \return CP_Coup
*/

COUP_Coup COUP_coup(PION_Pion, POS_Position);

/**
* \fn PION_Pion CP_obtenirPion(CP_Coup coup)
* \brief renvoie le pion d'un coup
* \author Maria Biancia Zugravu
* \return PION_Pion
*/

PION_Pion COUP_obtenirPion(COUP_Coup);

/**
* \fn POS_Position CP_obtenirPosition(CP_Coup coup)
* \brief renvoie la position d'un coup
* \author Maria Biancia Zugravu
* \return POS_Position
*/

POS_Position COUP_obtenirPosition(COUP_Coup);

/**
* \fn bool COUP_estValide(COUP_Coup)
* \brief indique si il coup est valide ou non
* \author Maria Biancia Zugravu
* \return bool
*/

bool COUP_estValide(COUP_Coup);

/**
* \fn bool COUP_sontEgaux(COUP_Coup, COUP_Coup)
* \brief indique si les coups sont égaux ou non
* \author Maria Biancia Zugravu
* \return bool
*/

bool COUP_sontEgaux(COUP_Coup, COUP_Coup);

#endif
