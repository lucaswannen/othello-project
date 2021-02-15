/**
  * \file Couleur.h
  * \brief TAD couleur
  * \author Maria-Biancia Zugravu
  * \version 1.0
  * \date 01/12/2019
  */

#ifndef __COULEUR__
#define __COULEUR__

#include <stdbool.h>

/**
* \enum CLR_Couleur Couleur.h "include/Couleur.h"
* \brief il y a dans l'énumération les différentes couleurs d'un pion, sachant qu'un pion peut être de couleur 'VIDE'
* \author Maria-Biancia Zugravu
*/

typedef enum CLR_Couleur {BLANC,NOIR,VIDE} CLR_Couleur;

/**
* \fn CLR_Couleur CLR_changerCouleur(CLR_Couleur couleur)
* \brief renvoie la couleur inverse de celle en entrée (l'inverse de NOIR et BLANC et inversement)
* \author Maria-Biancia Zugravu
* \param couleur la couleur dont on veut l'inverse
* \return CLR_Couleur
*/

CLR_Couleur CLR_changerCouleur(CLR_Couleur);

/**
* \fn bool CL_changerCouleur(CLR_Couleur couleur1,CLR_Couleur couleur1)
* \brief rretourne vrai si les couleurs sont égals,faux sinon
* \author Maria-Biancia Zugravu
* \param couleur1 couleur2 les couleurs qui sont à comparer
* \return bool
*/
bool CLR_sontEgales(CLR_Couleur, CLR_Couleur);

#endif
