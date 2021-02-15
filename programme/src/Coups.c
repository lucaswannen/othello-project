/**
 * \file Coups.c
 * \brief Implementation du TAD Coups
 * \author Maria Bianca Zugravu
 * \version 1.0
 */

#include "Coups.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


CPS_Coups CPS_coups(){
  CPS_Coups cps;
  cps.nbCoups=0;
  return cps;
}

void CPS_decalageVersLaGauche(CPS_Coups* coups, unsigned int indice){
  unsigned int i;
  for (i=indice;i<CPS_nbCoups(*coups);i++){
    (*coups).lesCoups[i]=(*coups).lesCoups[i+1];
  }
}
unsigned int CPS_obtenirIndiceDUnCoup(CPS_Coups coups, COUP_Coup coup){
  assert (CPS_estPresent(coups, coup));
  unsigned int indice=1;
  bool nonTrouve = false;
  while (!nonTrouve){
    nonTrouve=COUP_sontEgaux(CPS_iemeCoup(coups,indice),coup);
    indice++;
  }
  return (indice-1);
}

bool CPS_estPresent(CPS_Coups cps, COUP_Coup leCoup){
  bool estPresent=false;
  unsigned int i=0;
  while((i<NB_CPS_MAX) && (!estPresent)){
    if (COUP_sontEgaux(cps.lesCoups[i],leCoup))
      estPresent=true;
    i++;
  }
  return estPresent;
}
bool CPS_estCoupValide(CPS_Coups lesCoups, COUP_Coup leCoup){
  /* fonction qui vérifie que le coup n'est pas en dehors des limites du plateau
     et qu'il n'est pas été fait avant
   */
  return (COUP_estValide(leCoup) && !(CPS_estPresent(lesCoups,leCoup)));
}

COUP_Coup CPS_iemeCoup(CPS_Coups lesCoups, unsigned int i){
  return lesCoups.lesCoups[i];
}

void CPS_ajouter(CPS_Coups* lesCoups, COUP_Coup leCoup){
  if (!(CPS_estPresent(*lesCoups,leCoup))){
    (*lesCoups).nbCoups = (*lesCoups).nbCoups + 1;
    (*lesCoups).lesCoups[(*lesCoups).nbCoups] = leCoup;
  }
}

unsigned int CPS_nbCoups(CPS_Coups lesCoups){
  return lesCoups.nbCoups;
}

bool CPS_egal(CPS_Coups cps1, CPS_Coups cps2){
  bool egal;
  unsigned int i = 1;
  if (CPS_nbCoups(cps1)==CPS_nbCoups(cps2)) {
    egal = true;
    while (i<=CPS_nbCoups(cps1) && egal) {
      egal = COUP_sontEgaux(CPS_iemeCoup(cps1,i),CPS_iemeCoup(cps2,i));
      i++;
    }
  }else{
    egal = false;
  }
  return egal;  
}

void CPS_supprimer(CPS_Coups* coups, COUP_Coup coup){
  unsigned int indiceCoup;
  if (CPS_estPresent(*coups,coup)){
    indiceCoup = CPS_obtenirIndiceDUnCoup(*coups,coup);
    CPS_decalageVersLaGauche(coups,indiceCoup);
    (*coups).nbCoups = (*coups).nbCoups-1;
  }
}
