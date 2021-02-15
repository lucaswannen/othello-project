/**
 * \file coupsPossibles.c
 * \brief fonction coupsPossibles
 * \version 1.0
 */

#include "coupsPossibles.h"


bool testCoup(COUP_Coup coup, PL_Plateau plateau){
    int i, j ,k;
    CLR_Couleur couleurCaseATester;
    CLR_Couleur couleurJoueur = PION_obtenirCouleur(COUP_obtenirPion(coup));
    POS_Position positionTestee;
    bool resultat = 0;
    int abscisse, ordonnee, newAbscisse, newOrdonnee;
    abscisse = POS_obtenirAbcisse(COUP_obtenirPosition(coup));
    ordonnee = POS_obtenirOrdonnee(COUP_obtenirPosition(coup));
    //On vérifie que la case à tester est bien vide.
    if (PL_caseVide(plateau,COUP_obtenirPosition(coup))){
        i = -1;
        //Pour chaque ligne.
        while ((i<2) && (resultat == 0)){
            j = -1;
            //Pour chaque colonne
            while ((j<2) && (resultat == 0)){
                //On va checker la case adjacente dans chaque direction.
                //Si les coordonnées de la case testée sont bien des coordonnées correctes, qui ne sortent pas des limites du plateau.
                if ((1<=abscisse+i) && (abscisse+i<=8) && (1<=ordonnee+j) && (ordonnee+j<=8)){
                    positionTestee = POS_position(abscisse + i, ordonnee + j);
                    //Si la case testée n'est pas vide.
                    if (!PL_caseVide(plateau, positionTestee)){
                        couleurCaseATester = PION_obtenirCouleur(PL_obtenirPion(plateau, positionTestee));
                        //Et enfin si la couleur de la case testée est celle de l'adversaire.
                        if (!CLR_sontEgales(couleurCaseATester, couleurJoueur)){
                            //Alors la case est valide : On commence la recherche dans cette direction.
                            newAbscisse = abscisse + 2*i;
                            newOrdonnee = ordonnee + 2*j;
                            //On check chaque case dans cette direction jusqu'à en trouver une qui valide ou invalide cette direction.
                            while ((!resultat) && (1<=newAbscisse) && (newAbscisse<=8) && (1<=newOrdonnee) && (newOrdonnee<=8) && (!PL_caseVide(plateau, POS_position(newAbscisse,newOrdonnee)))) {
                                resultat = (PION_obtenirCouleur(PL_obtenirPion(plateau, POS_position(newAbscisse,newOrdonnee))) == couleurJoueur);
                                //Si l'on trouve effectivement que cette case est un coup valide, alors on la sortie de la fonction doit être "vrai"
                                k++;
                                newAbscisse = newAbscisse + i;
                                newOrdonnee = newOrdonnee + j;
                            }
                        }
                    }
                }
                j++;
            }
            i++;
        }
    }
    return resultat;
}

bool coupPossible(COUP_Coup coup, PL_Plateau *plateau){
    return COUP_estValide(coup) && PL_caseVide(*plateau, COUP_obtenirPosition(coup)) && testCoup(coup, *plateau);
}

CPS_Coups coupsPossibles(PL_Plateau* plateau, CLR_Couleur couleurJoueur){
    CPS_Coups resultat = CPS_coups();
    int i,j;
    COUP_Coup CoupATester;

    for (i=1; i<9; i++){
        for (j=1; j<9; j++){
            CoupATester = COUP_coup(PION_pion(couleurJoueur), POS_position(i,j));
            if (coupPossible(CoupATester, plateau)){
                CPS_ajouter(&resultat, CoupATester);
            }
        }
    }
    return resultat;
}
