/*
 * \file testRetournerPionsDansUneDirection.c
 * \brief Tests de retournerPionsDansUneDirection
 * \author WANNENMACHER Lucas
 */



#include <stdlib.h>
#include <CUnit/Basic.h>
#include "retournerPions.h"



int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_retournerPionsDansUneDirection(void) {
  //cas des lignes
  PL_Plateau plateau;
  CPS_Coups cps1 = CPS_coups(); /* noirs*/
  CPS_Coups cps2 = CPS_coups(); /* blancs */
  PL_initialiser(&plateau);
  CLR_Couleur couleur_b= BLANC ;
  CLR_Couleur couleur_n= NOIR ;
  PION_Pion pionN = PION_pion(couleur_n);
  PION_Pion pionB = PION_pion(couleur_b);
  POS_Position Central_B = POS_position(3,3);
  POS_Position Droite_N = POS_position(4,3);
  POS_Position Droite_B = POS_position(5,3);
  PL_poserPion(&plateau,Central_B,pionB);
  CPS_ajouter(&cps2,COUP_coup(pionB,Central_B));
  PL_poserPion(&plateau,Droite_N,pionN);
  CPS_ajouter(&cps1, COUP_coup(pionN,Droite_N));
  PL_poserPion(&plateau,Droite_B,pionB);
  CPS_ajouter(&cps2, COUP_coup(pionB,Droite_B));

  COUP_Coup coup = COUP_coup(pionB, Central_B);
  retournerPionsDansUneDirection(&plateau,coup,&cps1,&cps2,1,0);
  retournerPionsDansUneDirection(&plateau,coup,&cps1,&cps2,-1,0);
  retournerPionsDansUneDirection(&plateau,coup,&cps1,&cps2,0,1);
  retournerPionsDansUneDirection(&plateau,coup,&cps1,&cps2,0,-1);
  CU_ASSERT_TRUE(PION_obtenirCouleur(PL_obtenirPion(plateau,Droite_N))== couleur_b);

  //cas des diagonales
  PL_Plateau plateau2;
  PL_initialiser(&plateau2);
  CPS_Coups cps11 = CPS_coups(); /* noirs*/
  CPS_Coups cps22 = CPS_coups(); /* blancs */
  POS_Position Central_B2 = POS_position(3,3);
  POS_Position Diag_N = POS_position(4,4);
  POS_Position Diag_B = POS_position(5,5);
  PL_poserPion(&plateau2,Central_B2,pionB);
  CPS_ajouter(&cps22,COUP_coup(pionB,Central_B2));
  PL_poserPion(&plateau2,Diag_N,pionN);
  CPS_ajouter(&cps11, COUP_coup(pionN,Diag_N));
  PL_poserPion(&plateau2,Diag_B,pionB);
  CPS_ajouter(&cps22, COUP_coup(pionB,Diag_B));
  COUP_Coup coup2 = COUP_coup(pionB, Central_B2);
  retournerPionsDansUneDirection(&plateau2,coup2,&cps11,&cps22,1,1);
  retournerPionsDansUneDirection(&plateau2,coup2,&cps11,&cps22,-1,1);
  retournerPionsDansUneDirection(&plateau2,coup2,&cps11,&cps22,1,-1);
  retournerPionsDansUneDirection(&plateau2,coup2,&cps11,&cps22,-1,-1);
  CU_ASSERT_TRUE(PION_obtenirCouleur(PL_obtenirPion(plateau2,Diag_N))== couleur_b);

}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : retournerPionsDansUneDirection", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "retournerPionsDansUneDirection", test_retournerPionsDansUneDirection))
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
