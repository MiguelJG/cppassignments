#include "TuringMachine.h"

int main(){
  bool debug = false;
  cout << "Introduzca el numero de iteraciones: ";
  int num = 0;
  cin >> num;
  //cout << "Introduzca el numero de hormigas: ";
  //int numhor = 0;
  //cin >> numhor;
  cout << "¿Modo debug?(Si 1, no 0) ";
  cin >> debug;
  cout << "Introduzca el color base (0 blanco, 1 negro): ";
  int color = 0;
  cin >> color;
  TuringMachine maquina = TuringMachine(color, 4);
  for(int i = 0; i < num; i++){
    if(i == num - 1)
      debug = true;
    maquina.compute(debug);
  }
}
