/*
 * \file testTADPlateau.c
 * \brief Tests des fonctions du TAD Plateau
 * \author Maria Bianca Zugravu
 */

#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Plateau.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_PL_initialiser() {
  PL_Plateau plateau;
  unsigned int i,j;
  PL_initialiser(&plateau);
  for (i=1; i<=LARGEUR; i++) {
    for (j=1; j<=HAUTEUR; j++) {
      CU_ASSERT_TRUE(PL_caseVide(plateau,POS_position(i,j)));
    }
  }
}

void test_PL_estRempli() {
  PL_Plateau plateau;
  unsigned int i,j;
  PL_initialiser(&plateau);
  for (i=1; i<=LARGEUR; i++){
    for (j=1; j<=HAUTEUR; j++){
      PL_fixerPionDansCase(&plateau,POS_position(i,j),PION_pion(NOIR));
    }
  }
  CU_ASSERT_FALSE(PL_estRempli(plateau));
  
}

void test_PL_poserPion() {
  PL_Plateau plateau;
  PL_initialiser(&plateau);
  PION_Pion pion = PION_pion(NOIR);
  POS_Position pos = POS_position(1,1);
  PL_poserPion(&plateau,pos,pion);
  CU_ASSERT_TRUE(PION_sontEgaux(PL_obtenirPion(plateau,pos),pion));
  CU_ASSERT_FALSE(PL_caseVide(plateau,pos));
}

void test_PL_enleverPion() {
  PL_Plateau pl;
  PL_initialiser(&pl);
  PION_Pion pion = PION_pion(BLANC);
  POS_Position pos = POS_position(1,1);
  PL_poserPion(&pl,pos,pion);
  PL_enleverPion(&pl,pos);
  CU_ASSERT_TRUE(PL_caseVide(pl,pos));
}

void test_PL_retournerPion() {
  PL_Plateau pl;
  PL_initialiser(&pl);
  PION_Pion pion = PION_pion(NOIR);
  POS_Position pos = POS_position(1,1);
  PL_poserPion(&pl,pos,pion);
  PL_retournerPion(&pl,pos);
  PION_retournerPion(&pion);
  CU_ASSERT_TRUE(PION_sontEgaux(PL_obtenirPion(pl,pos),pion));
}

void test_PL_egal() {
  PL_Plateau plateau1, plateau2;
  PL_initialiser(&plateau1);
  PL_initialiser(&plateau2);
  PION_Pion pion = PION_pion(NOIR);
  unsigned int i,j;
  for (i=1; i<2; i++) {
    for (j=1; j<2; j++) {
      POS_Position pos = POS_position(i,j);
      PL_poserPion(&plateau1,pos,pion);
      PL_poserPion(&plateau2,pos,pion);
    }
  }
  CU_ASSERT_TRUE(PL_sontPlateuxEgaux(plateau1,plateau2));
}

void test_PL_copier() {
  PL_Plateau plateau, plateauCopie;
  PL_initialiser(&plateau);
  PL_poserPion(&plateau,POS_position(1,1),PION_pion(NOIR));
  PL_copier(&plateauCopie,plateau);
  CU_ASSERT_TRUE(PL_sontPlateuxEgaux(plateauCopie,plateau));
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD Plateau", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "PL_initialiser", test_PL_initialiser))
      || (NULL == CU_add_test(pSuite, "PL_poserPion", test_PL_poserPion))
      || (NULL == CU_add_test(pSuite, "PL_enleverPion", test_PL_enleverPion))
      || (NULL == CU_add_test(pSuite, "PL_retournerPion", test_PL_retournerPion))
      || (NULL == CU_add_test(pSuite, "PL_egal", test_PL_egal))
      || (NULL == CU_add_test(pSuite, "PL_estRempli", test_PL_estRempli))
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
