/*
 * \file testretournerPions.c
 * \brief Tests de retournerPions et retournerPionsDansUneDirection
 */


#include <CUnit/Basic.h>
#include "retournerPions.h"


int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_retournerPions(void) {
  PL_Plateau plateau;
  PL_initialiser(&plateau);
  CPS_Coups cps1 = CPS_coups();
  CPS_Coups cps2 = CPS_coups();
  CLR_Couleur couleur_b= BLANC ;
  CLR_Couleur couleur_n= NOIR ;
  PION_Pion pionN = PION_pion(couleur_n);
  PION_Pion pionB = PION_pion(couleur_b);

  POS_Position Central_B = POS_position(3,3);
  POS_Position Droite_N = POS_position(4,3);
  POS_Position Droite_B = POS_position(5,3);
  POS_Position Diag_N = POS_position(4,4);
  POS_Position Diag_B = POS_position(5,5);

  PL_poserPion(&plateau,Droite_N,pionN);
  PL_poserPion(&plateau,Droite_B,pionB);
  PL_poserPion(&plateau,Diag_N,pionN);
  PL_poserPion(&plateau,Diag_B,pionB);

  COUP_Coup coup = COUP_coup(pionB, Central_B);

  retournerPions(&plateau,coup,&cps1,&cps2);
  CU_ASSERT_TRUE(PION_obtenirCouleur(PL_obtenirPion(plateau,Droite_N))== couleur_b);
  CU_ASSERT_TRUE(PION_obtenirCouleur(PL_obtenirPion(plateau,Diag_N))== couleur_b);

}

void test_CoinHD_Diagonale_retournerPions(void){
  PL_Plateau plateau;
  PL_initialiser(&plateau);
  CPS_Coups cps1 = CPS_coups();
  CPS_Coups cps2 = CPS_coups();
  CLR_Couleur couleur_b= BLANC ;
  CLR_Couleur couleur_n= NOIR ;
  PION_Pion pionN = PION_pion(couleur_n);
  PION_Pion pionB = PION_pion(couleur_b);

  POS_Position Diag_N = POS_position(5,4);
  POS_Position Diag_B1 = POS_position(6,3);
  POS_Position Diag_B2 = POS_position(7,2);
  POS_Position CoinHD = POS_position(8,1);

  PL_poserPion(&plateau,Diag_N,pionN);
  PL_poserPion(&plateau,Diag_B1,pionB);
  PL_poserPion(&plateau,Diag_B2,pionB);

  COUP_Coup coupAPoser = COUP_coup(pionN, CoinHD);

  retournerPions(&plateau,coupAPoser,&cps1,&cps2);
  CU_ASSERT_TRUE(PION_obtenirCouleur(PL_obtenirPion(plateau,Diag_B1))==couleur_n);
  CU_ASSERT_TRUE(PION_obtenirCouleur(PL_obtenirPion(plateau,Diag_B2))==couleur_n);
}




int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : retournerPions", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "retournerPions", test_retournerPions))
      ||(NULL == CU_add_test(pSuite, "retournerPions_CoinHD_Diagonale", test_CoinHD_Diagonale_retournerPions))
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
