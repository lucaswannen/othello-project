/**
 * \file partieFinie.c
 * \brief fonction partieFinie
 * \version 1.0
 */

#include "partieFinie.h"

typedef struct GAGNANT_retour{
  CLR_Couleur couleurGagnant;
  bool egalite;
  unsigned int scoreGagnant;
}GAGNANT_retour;

unsigned int calculerScore(CPS_Coups coups){
  return CPS_nbCoups(coups);
}

bool peutJouer(PL_Plateau* plateau, CLR_Couleur joueur){
  return CPS_nbCoups(coupsPossibles(plateau, joueur)) > 0;
}

GAGNANT_retour gagnant(CLR_Couleur joueur1, CLR_Couleur joueur2, CPS_Coups coupsJ1, CPS_Coups coupsJ2){
  GAGNANT_retour resultat;
  resultat.couleurGagnant = VIDE;
  resultat.egalite = false;
  resultat.scoreGagnant = 0;
  if (calculerScore(coupsJ1) == calculerScore(coupsJ2)){
    resultat.egalite = true;
    resultat.scoreGagnant = calculerScore(coupsJ1);
  } else {
    if (calculerScore(coupsJ1)<calculerScore(coupsJ2) ){
      resultat.egalite = false;
      resultat.couleurGagnant = joueur2;
      resultat.scoreGagnant = calculerScore(coupsJ2);
    }else {
      resultat.egalite = false;
      resultat.couleurGagnant = joueur1;
      resultat.scoreGagnant = calculerScore(coupsJ1);      
    }
  }    
  return resultat;  
}

PF_retour partieFinie(PL_Plateau* plateau,CPS_Coups coupsJ1,CPS_Coups coupsJ2,CLR_Couleur joueur1,CLR_Couleur joueur2){
  PF_retour resultat;
  GAGNANT_retour rGagnant;
  bool partieFinie;
  partieFinie=false;
  if ((PL_estRempli(*plateau))||(!(peutJouer(plateau,joueur1))&&(!(peutJouer(plateau,joueur2))))){
    partieFinie=true;
    rGagnant=gagnant(joueur1,joueur2, coupsJ1,coupsJ2);
  }else{
    rGagnant=gagnant(joueur1,joueur2,coupsJ1,coupsJ2);
  }
  resultat.partieFinie=partieFinie;
  resultat.couleurGagnant=rGagnant.couleurGagnant;
  resultat.egalite=rGagnant.egalite;
  resultat.scoreGagnant=rGagnant.scoreGagnant;
  return resultat;
}
