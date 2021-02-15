/**
 * \file obtenirCoupIA.c
 * \brief fonction obtenirCoupIA
 * \version 1.0
 */

#include "obtenirCoupIA.h"
#include <stdlib.h>
#include <stdio.h>

int max(int a, int b){
  if (a>b)
    return a;
  else
    return b;
}

int min(int a, int b){
  if (a<b)
    return a;
  else
    return b;
}

int signe(int a){
  return a/abs(a);
}

int evaluer(PL_Plateau plateau, CLR_Couleur joueur){
  int matriceValeurCases[8][8] = {{1000,-200,50,12,12,50,-200,1000},
			   {-200,-400,0,0,0,0,-400,-200},
			   {50,0,5,1,1,5,0,50},
			   {12,0,1,10,10,1,0,12},
			   {12,0,1,10,10,1,0,12},
			   {50,0,5,1,1,5,0,50},
			   {-200,-400,0,0,0,0,-400,-200},
			   {1000,-200,50,12,12,50,-200,1000}};
  unsigned int i, j;
  PION_Pion pion = PION_pion(joueur);
  POS_Position pos, posCoin;
  int scoreJoueur = 0;
  for (i=1;i<=LARGEUR;i++){
    for (j=1;j<=HAUTEUR;j++){
      pos = POS_position(i,j);
      if (!PL_caseVide(plateau, pos)){
        if (PION_sontEgaux(PL_obtenirPion(plateau,pos),pion)){
          if ((i==2 || i==7) && (j==2 || j==7)){
            posCoin = POS_position(i+signe(i-4), j+signe(j-4));
            //posCoin = POS_position(i+((i-4)/abs(i-4)), j+((j-4)/abs(j-4)));
            if (!PL_caseVide(plateau,posCoin)){
              if (PION_sontEgaux(PL_obtenirPion(plateau, posCoin),pion)){
                scoreJoueur = scoreJoueur + 100;
              }
            }
          }
          else{
            scoreJoueur = scoreJoueur + matriceValeurCases[i-1][j-1];
          }
        }
      }      
    }
  }
  return scoreJoueur;
}

int scoreDUnCoup(PL_Plateau* plateau, COUP_Coup coup, CLR_Couleur joueurRef,CPS_Coups coupsJ1, CPS_Coups coupsJ2, unsigned int profondeur, int alpha, int beta){
  PL_Plateau copiePlateau;
  PL_copier(&copiePlateau,*plateau);
  jouerCoup(&copiePlateau,coup,&coupsJ1,&coupsJ2);
  if ((partieFinie(&copiePlateau,coupsJ1,coupsJ2,joueurRef,CLR_changerCouleur(joueurRef)).partieFinie) || (profondeur==0)){
    return evaluer(copiePlateau,joueurRef);
  }else{
    return alphaBeta(&copiePlateau,joueurRef, CLR_changerCouleur(joueurRef),coupsJ1,coupsJ2,profondeur-1,alpha,beta);
  }
}

int alphaBeta(PL_Plateau* plateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant,CPS_Coups coupsJ1, CPS_Coups coupsJ2, unsigned int profondeur, int alpha, int beta){
  CPS_Coups cpsPossibles = coupsPossibles(plateau,joueurCourant);
  int resultat,score;
  unsigned int i;
  if (CPS_nbCoups(cpsPossibles)>0){
    resultat = scoreDUnCoup(plateau,CPS_iemeCoup(cpsPossibles,1),joueurRef, coupsJ1, coupsJ2,profondeur,alpha,beta);
  }
  for (i=2;i<=CPS_nbCoups(cpsPossibles);i++){
    score = scoreDUnCoup(plateau,CPS_iemeCoup(cpsPossibles,i), joueurRef,coupsJ1,coupsJ2,profondeur,alpha,beta);
    /* cas du joueur à minimiser */
    if (joueurRef==joueurCourant){
      resultat = min(score,resultat);
      if (resultat<beta){
	beta = resultat;
	/* condition pour traiter que les branches intéressantes de l'arbre*/
	if (alpha>beta){
	  return resultat;
	}
      }
    }
    /* cas du joueur à maximiser */
    else{
      resultat = max(score,resultat);
      if (resultat>alpha){
	alpha=resultat;
	if (alpha>beta){
	  return resultat;
	}
      }
    }
  }
  return resultat;
}

COUP_Coup obtenirCoupIA(PL_Plateau* plateau, CLR_Couleur couleur, CPS_Coups coupsJ1, CPS_Coups coupsJ2){
  CPS_Coups cpsPossibles = coupsPossibles(plateau, couleur);
  COUP_Coup resultat = CPS_iemeCoup(cpsPossibles,1);
  int score;
  int alpha = -1000;
  int beta = 1000;
  unsigned int profondeur = 5; 
  int meilleurScore = scoreDUnCoup(plateau,resultat,couleur, coupsJ1, coupsJ2,profondeur,alpha,beta);
  for (unsigned int i=2;i<=CPS_nbCoups(cpsPossibles);i++){
    score = scoreDUnCoup(plateau,CPS_iemeCoup(cpsPossibles,i),couleur,coupsJ1, coupsJ2,profondeur,alpha,beta);
    if (score>meilleurScore){
      resultat = CPS_iemeCoup(cpsPossibles,i);
      meilleurScore = score;
    }
  }
  return resultat;
}
