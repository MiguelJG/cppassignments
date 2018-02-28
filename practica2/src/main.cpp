#include "TuringMachine.h"
#include <ncurses.h>


int main(){
  cout << "Introduzca el numero de iteraciones: ";
  int num = 0;
  cin >> num;
  TuringMachine maquina = TuringMachine();
  for(int i = 0; i < num; i++){
    maquina.compute();
  }
  endwin();
}
