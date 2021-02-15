/*
 * \file testTADCoups.c
 * \brief Tests des fonctions du TAD Coups
 */


#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Coups.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_CPS_coups(void) {
  CU_ASSERT_TRUE(CPS_nbCoups(CPS_coups())==0);
}

void test_CPS_ajouter(void) {
  COUP_Coup coup = COUP_coup(PION_pion(BLANC),POS_position(1,1));
  CPS_Coups coups = CPS_coups();
  unsigned int nbCoupsOld = CPS_nbCoups(coups);
  CPS_ajouter(&coups,coup);
  CU_ASSERT_TRUE(CPS_nbCoups(coups)==nbCoupsOld+1);
}

void test_CPS_estPresent() {
  CPS_Coups cps = CPS_coups();
  COUP_Coup cp1 = COUP_coup(PION_pion(BLANC),POS_position(1,1));
  COUP_Coup cp2 = COUP_coup(PION_pion(NOIR),POS_position(1,4));
  CPS_ajouter(&cps,cp1);
  CU_ASSERT_TRUE(CPS_estPresent(cps,cp1));
  CU_ASSERT_FALSE(CPS_estPresent(cps,cp2));
}

void test_CPS_iemeCoup() {
  CPS_Coups cps = CPS_coups();
  COUP_Coup c1 = COUP_coup(PION_pion(BLANC),POS_position(1,1));
  COUP_Coup c2 = COUP_coup(PION_pion(NOIR),POS_position(2,2));
  CPS_ajouter(&cps,c1);
  CPS_ajouter(&cps,c2);
  CU_ASSERT_TRUE(COUP_sontEgaux(CPS_iemeCoup(cps,1),c1));
  CU_ASSERT_TRUE(COUP_sontEgaux(CPS_iemeCoup(cps,2),c2));
}

void test_CPS_egal() {
  CPS_Coups cps1 = CPS_coups();
  CPS_Coups cps2 = CPS_coups();
  COUP_Coup cp;
  for (unsigned int i=1; i<=3; i++) {
    cp = COUP_coup(PION_pion(BLANC),POS_position(1,i));
    CPS_ajouter(&cps1,cp);
    CPS_ajouter(&cps2,cp);
  }
  CU_ASSERT_TRUE(CPS_egal(cps1,cps2));
  CPS_ajouter(&cps1,COUP_coup(PION_pion(NOIR),POS_position(3,2)));
  CU_ASSERT_FALSE(CPS_egal(cps1,cps2));
}

void test_supprimer(void){
  CPS_Coups cps = CPS_coups();
  COUP_Coup c1 = COUP_coup(PION_pion(BLANC),POS_position(1,1));
  COUP_Coup c2 = COUP_coup(PION_pion(NOIR),POS_position(2,2));
  COUP_Coup c3 = COUP_coup(PION_pion(NOIR),POS_position(3,3));
  CPS_ajouter(&cps,c1);
  CPS_ajouter(&cps,c2);
  CPS_ajouter(&cps,c3);
  CPS_supprimer(&cps,c2);
  CU_ASSERT_TRUE(CPS_nbCoups(cps)==2);
  CU_ASSERT_TRUE(COUP_sontEgaux(CPS_iemeCoup(cps,2),c2));
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : TAD Coups", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL==CU_add_test(pSuite, "CPS_coups", test_CPS_coups))
      || (NULL==CU_add_test(pSuite, "CPS_ajouter", test_CPS_ajouter))
      || (NULL==CU_add_test(pSuite, "CPS_estPresent", test_CPS_estPresent))
      || (NULL==CU_add_test(pSuite, "CPS_iemeCoup", test_CPS_iemeCoup))
      || (NULL==CU_add_test(pSuite, "CPS_egal", test_CPS_egal))
      || (NULL==CU_add_test(pSuite, "CPS_supprimer", test_supprimer))
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
