/*
 * \file testoupsossibles.c
 * \brief Tests de coupsPossibles.c
 */


#include <CUnit/Basic.h>
#include "coupsPossibles.h"
#include "initialiser.h"
#include "jouerCoup.h"


int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_CoupsPossiblesApresInitialisation(void) {
  PL_Plateau plateau;
  CPS_Coups coupsJ1 = CPS_coups();
  CPS_Coups coupsJ2 = CPS_coups();
  initialiser(&plateau, &coupsJ1, &coupsJ2);
  CLR_Couleur couleur_b= BLANC;
  CLR_Couleur couleur_n= NOIR;

  CU_ASSERT_TRUE(CPS_nbCoups(coupsPossibles(&plateau,couleur_n))==4);
  CU_ASSERT_TRUE(CPS_nbCoups(coupsPossibles(&plateau,couleur_b))==4);
}

void test_CoupsPossiblesApresAvoirJoueUnCoup(void){
  PL_Plateau plateau;
  CPS_Coups coupsJ1 = CPS_coups();
  CPS_Coups coupsJ2 = CPS_coups();
  initialiser(&plateau, &coupsJ1, &coupsJ2);
  CLR_Couleur couleur_b= BLANC;
  CLR_Couleur couleur_n= NOIR;
  POS_Position posCoupN = POS_position(5,3);
  PION_Pion pionCoupN = PION_pion(couleur_n);
  COUP_Coup coupN = COUP_coup(pionCoupN,posCoupN);
  jouerCoup(&plateau,coupN, &coupsJ1,&coupsJ2);
  CU_ASSERT_TRUE(CPS_nbCoups(coupsPossibles(&plateau,couleur_n))==3);
  CU_ASSERT_TRUE(CPS_nbCoups(coupsPossibles(&plateau,couleur_b))==3);
  POS_Position posCoupB = POS_position(6,3);
  PION_Pion pionCoupB = PION_pion(couleur_b);
  COUP_Coup coupB = COUP_coup(pionCoupB,posCoupB);
  jouerCoup(&plateau,coupB,&coupsJ1,&coupsJ2);
  CU_ASSERT_TRUE(CPS_nbCoups(coupsPossibles(&plateau,couleur_n))==4);
  CU_ASSERT_TRUE(CPS_nbCoups(coupsPossibles(&plateau,couleur_b))==5);
 
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : jouerCoup", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "coupsPossibles", test_CoupsPossiblesApresInitialisation))
      || (NULL == CU_add_test(pSuite, "coupsPossibles", test_CoupsPossiblesApresAvoirJoueUnCoup))
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
