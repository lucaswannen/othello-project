/**
  * \file Position.h
  * \brief CTAD Position fichier.h
  * \author Maria Bianca Zugravu
  * \version 1.0
  */

#ifndef __POSITION__
#define __POSITION__

#include <stdbool.h>

/**
* \struct POS_Position Position.h "include/Position.h"
* \brief represente une abcisse et une ordonnee
*/

typedef struct POS_Position{
  unsigned int abcisse;
  unsigned int ordonnee;
} POS_Position;

/**
* \fn POS_Position POS_position(unsigned int, unsigned int)
* \brief renvoie la position a partir des deux coordonnes indiquees
* \return POS_Position
*/

POS_Position POS_position(unsigned int, unsigned int);

/**
* \fn unsigned int POS_obtenirAbcisse(POS_Position)
* \brief renvoie l'abcisse d'une position
* \return unsigned int
*/

unsigned int POS_obtenirAbcisse(POS_Position);

/**
* \fn unsigned int POS_obtenirOrdonnee(POS_Position)
* \brief renvoie l'ordonnee d'une position
* \return unsigned int
*/

unsigned int POS_obtenirOrdonnee(POS_Position);

/**
* \fn bool POS_sontEgales(POS_Position, POS_Position)
* \brief indique si deux positions sont egales ou non
* \return bool
*/

bool POS_sontEgales(POS_Position, POS_Position);

#endif
