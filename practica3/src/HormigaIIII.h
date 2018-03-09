#pragma once
#include "Hormiga.h"

class HormigaIIII: public Hormiga{
public:

  int next_pos(int color);

  HormigaIIII(int i, int j, int dir) : Hormiga(i, j, dir){};

};


int HormigaIIII::next_pos(int color){
  if(color == BLANCO){
    this->Hormiga::girar_izquierda();
    this->Hormiga::mover();
    return NEGRO;
  } else if(color == NEGRO){
    this->Hormiga::girar_izquierda();
    this->Hormiga::mover();
    return AZUL;
  } else if(color == AZUL){
    this->Hormiga::girar_izquierda();
    this->Hormiga::mover();
    return ROSA;
  } else if(color == ROSA){
    this->Hormiga::girar_izquierda();
    this->Hormiga::mover();
    return BLANCO;
  }
}
