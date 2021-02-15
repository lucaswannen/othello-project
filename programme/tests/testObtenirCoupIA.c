/*
 * \file testObtenirCoupIA.c
 * \brief Tests de la fonction obtenirCoupIA
 * \author Maria Bianca Zugravu
 */

#include <stdlib.h>
#include <stdio.h>
#include <CUnit/Basic.h>
#include "obtenirCoupIA.h"
#include "IHM.h"


int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_obtenirCoupIA_uneSeulePossibilite(){
  PL_Plateau plateau;
  PL_initialiser(&plateau);
  CPS_Coups coupsJ1 = CPS_coups();
  CPS_Coups coupsJ2 = CPS_coups();
  PION_Pion pionNoir = PION_pion(NOIR);
  PION_Pion pionBlanc = PION_pion(BLANC);
  CLR_Couleur blanc = BLANC;

  /* test avec une seule possibilité en ligne */
  PL_poserPion(&plateau,POS_position(1,1),pionNoir);
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(1,1)));
  PL_poserPion(&plateau,POS_position(2,2),pionNoir);
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(2,2)));
  PL_poserPion(&plateau,POS_position(2,1),pionBlanc);
  CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(2,1)));
  COUP_Coup coupIA = obtenirCoupIA(&plateau,blanc,coupsJ1,coupsJ2);
  COUP_Coup coupAttendu = COUP_coup(pionBlanc,POS_position(2,3));
  CU_ASSERT_TRUE(COUP_sontEgaux(coupIA,coupAttendu));

  /* test avec une seule possibilité en colonne */
  PL_Plateau plateau2;
  PL_initialiser(&plateau2);
  CPS_Coups coupsJ11 = CPS_coups();
  CPS_Coups coupsJ22 = CPS_coups();
  PL_poserPion(&plateau2,POS_position(1,1),pionBlanc);
  CPS_ajouter(&coupsJ22,COUP_coup(pionBlanc,POS_position(1,1)));
  PL_poserPion(&plateau2,POS_position(2,1),pionNoir);
  CPS_ajouter(&coupsJ11,COUP_coup(pionNoir,POS_position(2,1)));
  COUP_Coup coupIA2 = obtenirCoupIA(&plateau2,blanc,coupsJ11,coupsJ22);
  COUP_Coup coupAttendu2 = COUP_coup(pionBlanc,POS_position(3,1));
  CU_ASSERT_TRUE(COUP_sontEgaux(coupIA2,coupAttendu2));
}

void test_obtenirCoupIA_gagnerLeBord(){
  PL_Plateau plateau;
  PL_initialiser(&plateau);
  CPS_Coups coupsJ1 = CPS_coups();
  CPS_Coups coupsJ2 = CPS_coups();
  PION_Pion pionNoir = PION_pion(NOIR);
  PION_Pion pionBlanc = PION_pion(BLANC);
  CLR_Couleur noir = NOIR;
  PL_poserPion(&plateau,POS_position(3,6),pionNoir);
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(3,6)));
  PL_poserPion(&plateau,POS_position(3,7),pionNoir);
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(3,7)));
  PL_poserPion(&plateau,POS_position(4,4),pionNoir);
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(4,4)));
  PL_poserPion(&plateau,POS_position(5,3),pionNoir);
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(5,3)));
  PL_poserPion(&plateau,POS_position(5,5),pionNoir);
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(5,5)));
  
  PL_poserPion(&plateau,POS_position(2,5),pionBlanc);
  CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(2,5)));
  PL_poserPion(&plateau,POS_position(3,5),pionBlanc);
  CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(3,5)));
  PL_poserPion(&plateau,POS_position(4,5),pionBlanc);
  CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(4,5)));
  PL_poserPion(&plateau,POS_position(5,4),pionBlanc);
  CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(5,4)));
  PL_poserPion(&plateau,POS_position(6,3),pionBlanc);
  CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(6,3)));
  /* Dans cette configuration avec une profondeur = 3 l'IA doit choisir de jouer en (1,5)
   coup qui lui rapporte 3 pions adversaires et le bord. Il y aussi le coup en (7,2) 
  qui lui apportera 3 pions adversaires mais la position est moins strategique */
  COUP_Coup coupIA = obtenirCoupIA(&plateau,noir,coupsJ1,coupsJ2);
  COUP_Coup coupAttendu = COUP_coup(pionNoir,POS_position(1,5));
  CU_ASSERT_TRUE(COUP_sontEgaux(coupIA,coupAttendu));
}

void test_obtenirCoupIA_joueurBlancBloque(){
  PL_Plateau plateau;
  PL_initialiser(&plateau);
  CPS_Coups coupsJ1 = CPS_coups();
  CPS_Coups coupsJ2 = CPS_coups();
  PION_Pion pionNoir = PION_pion(NOIR);
  PION_Pion pionBlanc = PION_pion(BLANC);
  COUP_Coup coupHG = COUP_coup(pionNoir,POS_position(1,1));
  COUP_Coup coupHD = COUP_coup(pionNoir,POS_position(1,8));
  COUP_Coup coupBG = COUP_coup(pionNoir,POS_position(8,1));
  COUP_Coup coupBD = COUP_coup(pionNoir,POS_position(8,8));
  COUP_Coup coupIA;
  CLR_Couleur noir = NOIR;
  unsigned int i,j;
  for(j=2;j<8;j++){
    PL_poserPion(&plateau,POS_position(1,j),pionBlanc);
    CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(1,j)));
    PL_poserPion(&plateau,POS_position(8,j),pionBlanc);
    CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(8,j)));
  }
  for(i=2;i<8;i++){
    for(j=1;j<9;j++){
      PL_poserPion(&plateau,POS_position(i,j),pionBlanc);
      CPS_ajouter(&coupsJ2,COUP_coup(pionBlanc,POS_position(i,j)));
    }
  }
  PL_retournerPion(&plateau,POS_position(4,4));
  CPS_ajouter(&coupsJ1,COUP_coup(pionNoir,POS_position(4,4)));
  CPS_supprimer(&coupsJ2,COUP_coup(pionBlanc,POS_position(4,4)));
  
  coupIA = obtenirCoupIA(&plateau,noir,coupsJ1,coupsJ2);
  CU_ASSERT_TRUE(COUP_sontEgaux(coupIA,coupHG) || COUP_sontEgaux(coupIA,coupHD) || COUP_sontEgaux(coupIA,coupBG) || COUP_sontEgaux(coupIA,coupBD));
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : ObtenirCoupIA", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "obtenirCoupIA_uneSeulePossibilite", test_obtenirCoupIA_uneSeulePossibilite))
      || (NULL == CU_add_test(pSuite, "obtenirCoupIA_gagnerLeBord", test_obtenirCoupIA_gagnerLeBord))
      || (NULL == CU_add_test(pSuite, "obtenirCoupIA_joueurBlancBloque", test_obtenirCoupIA_joueurBlancBloque))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}
