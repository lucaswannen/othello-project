/*
 * \file testTADPion.c
 * \brief Tests des fonctions du TAD Pion
 * \author Maia Bianca ZUGRAVU
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Pion.h"
#include "Couleur.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_PION_obtenirCouleur() {
  CU_ASSERT_TRUE(PION_obtenirCouleur(PION_pion(NOIR))==NOIR);
}

void test_PION_retournerPion() {
  PION_Pion pion = PION_pion(NOIR);
  PION_retournerPion(&pion);
  CU_ASSERT_TRUE(PION_obtenirCouleur(pion)==BLANC);
}

void test_PION_egalite() {
  PION_Pion pion1 = PION_pion(NOIR);
  PION_Pion pion2 = PION_pion(NOIR);
  CU_ASSERT_TRUE(PION_sontEgaux(pion1,pion2));
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD Couleur", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "PION_obtenirCouleur", test_PION_obtenirCouleur))
      || (NULL == CU_add_test(pSuite, "PION_egalite", test_PION_egalite))
      || (NULL == CU_add_test(pSuite, "PION_retourner", test_PION_retournerPion))
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
