/*
 * \file testTADCoup.c
 * \brief Tests des fonctions du TAD Coup
 * \author Maria Bianca Zugravu
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Coup.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_CP_obtenirPion(void) {
  COUP_Coup coup;
  PION_Pion pion = PION_pion(NOIR);
  POS_Position position = POS_position(3,6);
  coup = COUP_coup(pion, position);
  CU_ASSERT_TRUE(PION_sontEgaux(COUP_obtenirPion(coup),pion));
}

void test_CP_obtenirPosition(void) {
  COUP_Coup coup;
  PION_Pion pion = PION_pion(NOIR);
  POS_Position position = POS_position(3,6);
  coup = COUP_coup(pion, position);
  CU_ASSERT_TRUE(POS_sontEgales(COUP_obtenirPosition(coup),position));
}

void test_CP_egal() {
  PION_Pion pion = PION_pion(NOIR);
  POS_Position position = POS_position(3,6);
  COUP_Coup coup1 = COUP_coup(pion,position);
  COUP_Coup coup2 = COUP_coup(pion,position);
  CU_ASSERT_TRUE(COUP_sontEgaux(coup1,coup2));
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD Coup", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "CP_obtenirPion", test_CP_obtenirPion))
      || (NULL == CU_add_test(pSuite, "CP_obtenirPosition", test_CP_obtenirPosition))
      || (NULL == CU_add_test(pSuite, "CP_egal", test_CP_egal))
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
