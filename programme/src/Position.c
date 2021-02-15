/**
 * \file Position.c
 * \brief Implementation du TAD position
 * \author Maria Bianca Zugravu
 * \version 1.0
 */

#include "Position.h"
#include <assert.h>

POS_Position POS_position(unsigned int abcisse, unsigned int ordonnee){
  assert(1<=abcisse);
  assert(abcisse<=8);
  assert(1<=ordonnee);
  assert(ordonnee<=8);
  POS_Position pos;
  pos.abcisse = abcisse;
  pos.ordonnee = ordonnee;
  return pos;
}

unsigned int POS_obtenirAbcisse(POS_Position pos){
  return pos.abcisse;
}

unsigned int POS_obtenirOrdonnee(POS_Position pos){
  return pos.ordonnee;
}

bool POS_sontEgales(POS_Position pos1, POS_Position pos2){
  return ((pos1.abcisse==pos2.abcisse) && (pos1.ordonnee==pos2.ordonnee));
}
