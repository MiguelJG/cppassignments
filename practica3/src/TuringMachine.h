#pragma once
#include "Rejilla.h"
#include "Hormiga.h"
#include "HormigaDIDI.h"
#include "HormigaDDDD.h"
#include "HormigaIIII.h"
#include "HormigaIIDI.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/**Turing machine
 *
 * \brief Clase que la maquina de turing en la que se realiza el computo de las posiciones de las hormigas y el estado del tablero
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class TuringMachine{
  Rejilla tablero;
  vector<Hormiga*> hormigas;
  int inicioi;
  int fini;
  int inicioj;
  int finj;

  /** \brief Write
    *
    * Este metodo muestra por la salida estandar el estado actual de la maquinas
    */
  void write();

  /** \brief set_hormigas
    *
    * Este metodo le da su posicion inicial a las diferentes hormigas
    */
  void set_hormigas();

public:

  /** \brief Constructor por defecto
    *
    * Este metodo instancia un objeto de la clase Turing Machine con 1 sola hormiga y color base blanco
    */
  TuringMachine();

  /** \brief Constructor
    *
    *  \param int size numero de hormigas de la maquinas
    *  Este metodo instancia un objeto de la clase Turing Machine con un numero de hormigas dado y color base blanco
    */
  TuringMachine(int size);

  /** \brief Constructor
    *
    *  \param int size numero de hormigas de la maquinas
    *  \param int color color base de la rejilla
    *  Este metodo instancia un objeto de la clase Turing Machine con un numero de hormigas dado y color base dado
    */
  TuringMachine(int color, int size);

  /** \brief compute
    *
    * \param bool debug
    * Este metodo realiza una iteracion del funcionamiento de la maquina de turing , mostrando todos los pasos o no en duncion de debug
    */
  void compute(bool debug);
};

void TuringMachine::write(){
  if(hormigas[0]->get_i() < inicioi || hormigas[0]->get_j() > finj || hormigas[0]->get_j() < inicioj || hormigas[0]->get_i() > fini){
    inicioi = hormigas[0]->get_i() - 40;
    fini = hormigas[0]->get_i() + 41;
    inicioj = hormigas[0]->get_j() - 60;
    finj = hormigas[0]->get_j() + 61;
  }
  cout << endl;
  for(int i = inicioi; i < fini; i++){
    for(int j = inicioj; j < finj; j++){
      cout << tablero.write(i, j);
      bool hayhormiga = false;
      for(int k = 0; k < hormigas.size(); k++){
        if(hormigas[k]->get_i() ==  i && hormigas[k]->get_j() == j && !hayhormiga){
          cout << hormigas[k]->write() << DEFAULT << "";
          hayhormiga = true;
        }
      }
      if(!hayhormiga){
        cout << " " << DEFAULT << "";
      }
    }
    cout << endl;
  }
  cout << endl;
}

TuringMachine::TuringMachine(){
  hormigas.resize(1);
}

TuringMachine::TuringMachine(int size){
  hormigas.resize(0);
  this->set_hormigas();
}

TuringMachine::TuringMachine(int color, int size){
  tablero = Rejilla(color);
  hormigas.resize(0);
  this->set_hormigas();
}

void TuringMachine::compute(bool debug){
  if(debug)
    this->write();
  for(int i = 0; i < hormigas.size(); i++){
    int dummyi = hormigas[i]->get_i();
    int dummyj = hormigas[i]->get_j();
    int dummycolor = hormigas[i]->next_pos(tablero.colorPos(hormigas[i]->get_i(), hormigas[i]->get_j()));
    tablero.setPos(dummyi, dummyj, dummycolor);
  }
  if(debug)
    usleep(500000);
}

void TuringMachine::set_hormigas(){
  hormigas.push_back(new HormigaDIDI(-5,-5,NORTE));
  hormigas.push_back(new HormigaDDDD(10,10,NORTE));
  hormigas.push_back(new HormigaIIII(-10,-10,NORTE));
  hormigas.push_back(new HormigaIIDI(5,5,NORTE));
}
