/*
 * \file testTADPosition.c
 * \brief Tests des fonctions du TAD Position
 * \author ZUGRAVU Maria Bianca
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Position.h"

int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_POS_obtenirAbscisse(){
  POS_Position position = POS_position(3,6);
  CU_ASSERT_TRUE(POS_obtenirAbcisse(position)==3);
}

void test_POS_obtenirOrdonnee(){
  POS_Position position = POS_position(3,6) ;
  CU_ASSERT_TRUE(POS_obtenirOrdonnee(position)==6);
}

void test_POS_egalite() {
  POS_Position position1 = POS_position(3,3);
  POS_Position position2 = POS_position(3,3);
  CU_ASSERT_TRUE(POS_sontEgales(position1,position2));
}



int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD Position", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "POS_obtenirAbscisse", test_POS_obtenirAbscisse))
      || (NULL == CU_add_test(pSuite, "POS_obtenirOrdonnee", test_POS_obtenirOrdonnee))
      || (NULL == CU_add_test(pSuite, "POS_egalite", test_POS_egalite))
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
