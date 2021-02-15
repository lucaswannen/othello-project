/**
 * \file main.c
 * \brief le main
 * \version 1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "faireUnePartie.h"

void othello_aide(){
  printf("Aide du programme othello \n");
  printf("Les options possibles sont : \n");
  printf("- standard blanc|noir [profondeur>2] : permet de jouer contre l'ordinateur en lui donnant les blancs ou les noirs (par défaut la profondeur est egale à 5)\n");
  printf("- tournoi blanc|noir [profondeur>2] : permet de faire confronter notre IA à elle-même (par défaut la profondeur est egale à 5)\n");
}


int main(int argc, char** argv){
  char* mode = argv[1];
  CLR_Couleur couleurJoueurHumain;
  if (argc==3 && (!strcmp(mode,"standard") || !strcmp(mode,"tournoi")) && (!strcmp(argv[2],"noir") || !strcmp(argv[2],"blanc"))){
    if (!strcmp(argv[2],"noir")){
      couleurJoueurHumain = NOIR;
    }else{
      couleurJoueurHumain = BLANC;
    }
    faireUnePartie(mode,couleurJoueurHumain);
  }else{
    othello_aide();
  }
  return EXIT_SUCCESS;
}
 
