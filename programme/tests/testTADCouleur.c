/*
 * \file testTADCouleur.c
 * \brief Tests des fonctions du TAD Couleur
 * \author Maria Bianca ZUGRAVU
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Couleur.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_CL_changerCouleur(void) {
  CU_ASSERT_TRUE(CLR_changerCouleur(BLANC)==NOIR);
  CU_ASSERT_TRUE(CLR_changerCouleur(NOIR)==BLANC);
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
  if ((NULL == CU_add_test(pSuite, "test changerCouleur", test_CL_changerCouleur))
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
