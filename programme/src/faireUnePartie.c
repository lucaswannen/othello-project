#include "faireUnePartie.h"


void faireUnePartie(char* mode, CLR_Couleur couleurChoisieHumain){
  PL_Plateau plateau;
  COUP_Coup coup1,coup2;
  CPS_Coups cps1 = CPS_coups();
  CPS_Coups cps2 = CPS_coups();
  CLR_Couleur joueur2;
  CLR_Couleur joueur1;
  bool fini = false;
  if (CLR_sontEgales(couleurChoisieHumain,NOIR)){
    joueur1 = couleurChoisieHumain;
    joueur2 = CLR_changerCouleur(joueur1);
  }else{
    joueur2 = couleurChoisieHumain;
    joueur1 = CLR_changerCouleur(joueur2);    
  }
  initialiser(&plateau, &cps1, &cps2);
  printf("\n\n ####################### OTHELLO ####################### \n\n");
  fflush(stdout);
  printf("\n\n >>>>>>>>>>>>>>>> Le jeu commence... \n\n");
  fflush(stdout);
  while (!partieFinie(&plateau,cps1,cps2,joueur1,joueur2).partieFinie && !fini){
    /* system("@cls||clear"); */
    printf("\n\n ####################### OTHELLO ####################### \n\n");
    fflush(stdout);
    IHM_affichagePlateau(plateau,cps1,cps2);
    printf("\n >>>>>>>>>>>>>>>> C'est aux NOIRS de jouer! \n");
    fflush(stdout);
    coup1 = obtenirCoup(&plateau,joueur1,mode,cps1,cps2);
    jouerCoup(&plateau,coup1,&cps1,&cps2);
    /* system("@cls||clear"); */
    IHM_affichagePlateau(plateau,cps1,cps2);
    printf("\n >>>>>>>>>>>>>>>> C'est aux BLANCS de jouer! \n");
    fflush(stdout);
    if(CPS_nbCoups(coupsPossibles(&plateau,joueur2))>0){
      coup2 = obtenirCoup(&plateau,joueur2,mode,cps1,cps2);
      jouerCoup(&plateau,coup2,&cps1,&cps2);
    }else{
      printf("\n >>>>>>>>>>>>>>>> Plus de coup possible! \n");
      fini = true;
    }
    /* system("@cls||clear"); */
  }
  if(partieFinie(&plateau,cps1,cps2,joueur1,joueur2).partieFinie || fini){
    IHM_affichagePlateau(plateau,cps1,cps2);
    printf("\n\n ####################### PARTIE FINIE  ####################### \n\n");
    fflush(stdout);
    if(partieFinie(&plateau,cps1,cps2,joueur1,joueur2).egalite){
      printf(" >>>>>>>>>>>>>>>> Il y a égalité :D \n");
      fflush(stdout);
    }else{
      if(CLR_sontEgales(partieFinie(&plateau,cps1,cps2,joueur1,joueur2).couleurGagnant,NOIR)){
	printf(" >>>>>>>>>>>>>>>> Les NOIRS ont gagné avec %d points !\n",partieFinie(&plateau,cps1,cps2,joueur1,joueur2).scoreGagnant);
	fflush(stdout);
      }else{
	printf(" >>>>>>>>>>>>>>>> Les BLANCS ont gagné avec %d points !\n",partieFinie(&plateau,cps1,cps2,joueur1,joueur2).scoreGagnant);
	fflush(stdout);
      }
    }
  }
}
