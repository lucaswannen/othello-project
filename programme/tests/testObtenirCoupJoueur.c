/*
 * \file testObtenirCoupJoueur.c
 * \brief Tests de la fonction obtenirCoupJoueur
 * \author Maria Bianca Zugravu
 */

#include <stdlib.h>
#include <stdio.h>
#include <CUnit/Basic.h>
#include "obtenirCoupJoueur.h"
#include "initialiser.h"


int init_suite_success() {
  return 0;
}

int clean_suite_success() {
  return 0;
}

void test_obtenirCoupJoueur(){
  PL_Plateau plateau;
  CPS_Coups coupsJ1 = CPS_coups();
  CPS_Coups coupsJ2 = CPS_coups();
  CLR_Couleur couleurJoueur = NOIR;
  PL_initialiser(&plateau);
  initialiser(&plateau,&coupsJ1,&coupsJ2);
  COUP_Coup coup = obtenirCoupJoueur(&plateau, couleurJoueur);
  CU_ASSERT_TRUE(CPS_estPresent(coupsPossibles(&plateau,couleurJoueur),coup));
  /* faut rentrer dans la ligne de commande soit e3\n soit f4\n soit c5\n soit d6\n*/
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : ObtenirCoupJoueur", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests a la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "obtenirCoupJoueur", test_obtenirCoupJoueur)))
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
