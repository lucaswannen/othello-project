/**
 * \file retournerPions.c
 * \brief procedure qui retourne les pions a retourner
 * \author WANNENMACHER Lucas
 */

#include "retournerPions.h"
#include <stdio.h>
#include <stdbool.h>

/* cette fonction retourne les pions à retourner dans une direction */

void retournerPionsDansUneDirection(PL_Plateau* plateau,COUP_Coup coup, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2,int abscisse_direction, int ordonnee_direction){
  CLR_Couleur couleurCoup = PION_obtenirCouleur(COUP_obtenirPion(coup));
  CLR_Couleur couleurOpposee = CLR_changerCouleur(couleurCoup);
  int n = 0; //n représente le nombre de cases à retourner
  bool deja_retourne = false; //ce booleen sert à ne pas retourner plusieurs fois le meme pion
  bool a_croise_case_vide = false; //ce booleen sert à ecarter le cas où il croise une case vide
  POS_Position PosCoup = COUP_obtenirPosition(coup);
  POS_Position PosCase = PosCoup;
  while(((POS_obtenirAbcisse(PosCase)+abscisse_direction)>0)&&((POS_obtenirAbcisse(PosCase)+abscisse_direction)<9)&&((POS_obtenirOrdonnee(PosCase)+ordonnee_direction)>0)&&((POS_obtenirOrdonnee(PosCase)+ordonnee_direction)<9)&&(!deja_retourne)&&(!a_croise_case_vide)){
    PosCase = POS_position(POS_obtenirAbcisse(PosCase)+abscisse_direction,POS_obtenirOrdonnee(PosCase)+ordonnee_direction);
    if(PL_caseVide(*plateau,PosCase)){
      a_croise_case_vide = true;
    }
    else{
      if(PION_obtenirCouleur(PL_obtenirPion(*plateau,PosCase))==couleurOpposee){
	n++;
      }
      //si le prochain pion est de la couleur du pion posé, alors on retourne les pions entre ces deux pions
      if((PION_obtenirCouleur(PL_obtenirPion(*plateau,PosCase))==couleurCoup)){
        deja_retourne = true;
        if(n>0){
        for(int i = 1;i<=n;i++){
          PL_retournerPion(plateau,POS_position(POS_obtenirAbcisse(PosCoup)+i*abscisse_direction,POS_obtenirOrdonnee(PosCoup)+i*ordonnee_direction));
	  if (CLR_sontEgales(couleurCoup,NOIR)){
	    CPS_ajouter(coupsJ1, COUP_coup(PION_pion(couleurCoup), POS_position(POS_obtenirAbcisse(PosCoup)+i*abscisse_direction,POS_obtenirOrdonnee(PosCoup)+i*ordonnee_direction)));
	    CPS_supprimer(coupsJ2, COUP_coup(PION_pion(couleurOpposee),POS_position(POS_obtenirAbcisse(PosCoup)+i*abscisse_direction,POS_obtenirOrdonnee(PosCoup)+i*ordonnee_direction)));
	}else{
	    CPS_ajouter(coupsJ2, COUP_coup(PION_pion(couleurCoup), POS_position(POS_obtenirAbcisse(PosCoup)+i*abscisse_direction,POS_obtenirOrdonnee(PosCoup)+i*ordonnee_direction)));
	    CPS_supprimer(coupsJ1, COUP_coup(PION_pion(couleurOpposee),POS_position(POS_obtenirAbcisse(PosCoup)+i*abscisse_direction,POS_obtenirOrdonnee(PosCoup)+i*ordonnee_direction)));
	  }
	}
    }
  }
  }
  }
}


//cette procedure fait des appels de retournerPionsDansUneDirection pour chaque direction
void retournerPions(PL_Plateau *plateau,COUP_Coup coup, CPS_Coups* coupsJ1, CPS_Coups* coupsJ2){
  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,1,0);
  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,0,1);
  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,-1,0);
  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,0,-1);

  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,1,1);
  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,1,-1);
  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,-1,-1);
  retournerPionsDansUneDirection(plateau,coup,coupsJ1,coupsJ2,-1,1);

}
