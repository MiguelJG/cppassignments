#include "Rejilla.h"
#include "Hormiga.h"
#include <unistd.h>

class TuringMachine{
  Rejilla tablero;
  vector<Hormiga> hormigas;
  int inicioi;
  int fini;
  int inicioj;
  int finj;
  void write();

public:

  TuringMachine();

  TuringMachine(int size);

  TuringMachine(int color, int size);

  void compute();
};

void TuringMachine::write(){
  if(hormigas[0].get_i() < inicioi || hormigas[0].get_j() > finj || hormigas[0].get_j() < inicioj || hormigas[0].get_i() > fini){
    inicioi = hormigas[0].get_i() - 40;
    fini = hormigas[0].get_i() + 41;
    inicioj = hormigas[0].get_j() - 60;
    finj = hormigas[0].get_j() + 61;
  }
  cout << endl;
  for(int i = inicioi; i < fini; i++){

    for(int j = inicioj; j < finj; j++){
      cout << tablero.write(i, j);
      bool hayhormiga = false;
      for(int k = 0; k < hormigas.size(); k++){
        if(hormigas[k].get_i() ==  i && hormigas[k].get_j() == j && !hayhormiga){
          cout << hormigas[k].write() << DEFAULT << "";
          hayhormiga = true;
        }
      }
      if(!hayhormiga){
        cout << " " << DEFAULT << "";
      }
    }
            cout << endl;
  }
}

TuringMachine::TuringMachine(){
  hormigas.resize(1);
}

TuringMachine::TuringMachine(int size){
  hormigas.resize(size);
}

TuringMachine::TuringMachine(int color, int size){
  tablero = Rejilla(color);
  hormigas.resize(size);
}

void TuringMachine::compute(){
  this->write();
  cout << endl;
  for(int i = 0; i < hormigas.size(); i++){
    int dummyi = hormigas[i].get_i();
    int dummyj = hormigas[i].get_j();
    int dummycolor = hormigas[i].next_pos(tablero.colorPos(hormigas[i].get_i(), hormigas[i].get_j()));
    tablero.setPos(dummyi, dummyj, dummycolor);
  }
  usleep(25000);
}
