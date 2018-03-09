#pragma once
#include "Hormiga.h"

class HormigaDDDD: public Hormiga{
public:

  int next_pos(int color);

  HormigaDDDD(int i, int j, int dir) : Hormiga(i, j, dir){};

};


int HormigaDDDD::next_pos(int color){
  if(color == BLANCO){
    this->Hormiga::girar_derecha();
    this->Hormiga::mover();
    return NEGRO;
  } else if(color == NEGRO){
    this->Hormiga::girar_derecha();
    this->Hormiga::mover();
    return AZUL;
  } else if(color == AZUL){
    this->Hormiga::girar_derecha();
    this->Hormiga::mover();
    return ROSA;
  } else if(color == ROSA){
    this->Hormiga::girar_derecha();
    this->Hormiga::mover();
    return BLANCO;
  }
}
