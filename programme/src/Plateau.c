/**
 * \file Plateau.c
 * \brief Implementation du TAD plateau
 * \author Maria Bianca Zugravu
 * \version 1.0
 */

#include <assert.h>
#include "Plateau.h"
#include <stdlib.h>


/* accesseurs */

void PL_fixerCaseAVide(PL_Plateau* plateau, POS_Position pos, bool estVide){
  (*plateau)[POS_obtenirAbcisse(pos)-1][POS_obtenirOrdonnee(pos)-1].caseVide=estVide;
}

void PL_fixerPionDansCase(PL_Plateau* plateau, POS_Position pos, PION_Pion pion){
  (*plateau)[POS_obtenirAbcisse(pos)-1][POS_obtenirOrdonnee(pos)-1].pion=pion;
}

void PL_initialiser(PL_Plateau* plateau){
  unsigned int i,j;
  for (i=1;i<=LARGEUR;i++){
    for (j=1;j<=HAUTEUR;j++){
      PL_fixerCaseAVide(plateau,POS_position(i,j),true);
    }
  }
}

bool PL_caseVide(PL_Plateau plateau, POS_Position pos){
  return plateau[POS_obtenirAbcisse(pos)-1][POS_obtenirOrdonnee(pos)-1].caseVide;
}

bool PL_estRempli(PL_Plateau plateau){
  unsigned int i, j, plateauRempli=true;
  POS_Position position;
  i=1; j=1;
  while ((plateauRempli)&&(i<=8)){
    j=1;
    while((plateauRempli)&&(j<=8)){
      position=POS_position(i,j);
      if (PL_caseVide(plateau,position))
	plateauRempli=false;
      j++;
    }
    i++;
  }
  return plateauRempli;
}

PION_Pion PL_obtenirPion(PL_Plateau plateau, POS_Position pos){
  assert(!PL_caseVide(plateau,pos));
  return plateau[POS_obtenirAbcisse(pos)-1][POS_obtenirOrdonnee(pos)-1].pion;
}

void PL_poserPion(PL_Plateau* plateau, POS_Position pos, PION_Pion pion){
  assert(PL_caseVide(*plateau,pos));
  PL_fixerPionDansCase(plateau,pos,pion);
  PL_fixerCaseAVide(plateau,pos,false);
}

void PL_enleverPion(PL_Plateau* plateau, POS_Position pos){
  assert (!PL_caseVide(*plateau,pos));
  PL_fixerCaseAVide(plateau,pos,true);
}

void PL_retournerPion(PL_Plateau* plateau,POS_Position pos){
  assert (!PL_caseVide(*plateau,pos));
  PION_Pion pion=PL_obtenirPion(*plateau,pos);
  PION_Pion* ppion;
  ppion=&pion;
  PION_retournerPion(ppion);
  PL_fixerPionDansCase(plateau,pos,*ppion);
  PL_fixerCaseAVide(plateau,pos,false);

}

bool PL_sontCasesEgales(PL_Plateau plateau1, PL_Plateau plateau2, POS_Position pos){
  if (!PL_caseVide(plateau1,pos) && !PL_caseVide(plateau2,pos)) {
    return PION_sontEgaux(PL_obtenirPion(plateau1,pos),PL_obtenirPion(plateau2,pos));
  } else {
    return PL_caseVide(plateau1,pos)==PL_caseVide(plateau2,pos);
  }
}

bool PL_sontPlateuxEgaux(PL_Plateau plateau1, PL_Plateau plateau2){
  unsigned int i,j;
  bool sontEgaux = true;
  i=1;j=1;
  while (i<=HAUTEUR && sontEgaux) {
    j=1;
    while (j<=LARGEUR && sontEgaux) {
      sontEgaux = PL_sontCasesEgales(plateau1,plateau2,POS_position(i,j));
      j++;
    }
    i++;
  }
  return sontEgaux;
}

void PL_copier(PL_Plateau* plateauCopie, PL_Plateau plateauSource){
  POS_Position pos;
  unsigned int i,j;
  for (i=1; i<=LARGEUR; i++) {
    for (j=1; j<=HAUTEUR; j++) {
      pos = POS_position(i,j);
      PL_fixerCaseAVide(plateauCopie,pos,PL_caseVide(plateauSource,pos));
      if (!PL_caseVide(plateauSource,pos)) {
        PL_fixerPionDansCase(plateauCopie,pos,PL_obtenirPion(plateauSource,pos));
      }
    }
  }
}
