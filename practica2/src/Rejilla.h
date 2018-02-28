#include <iostream>
#include <vector>

using namespace std;
//https://misc.flogisoft.com/bash/tip_colors_and_formatting

#define WHITHE "\x1B[107m\x1B[30m" //colores
#define BLACK "\x1B[40m\x1B[97m"
#define DEFAULT "\x1B[39m\x1B[49m"
const int BLANCO = 0;
const int NEGRO = 1;

class Casilla{
  int color;//0 blanco| 1 negro
  int i;
  int j;
public:

  Casilla();

  Casilla(int i, int j, int color);

  int get_i();

  void set_i(int i);

  int get_j();

  void set_j(int j);

  int get_color();

  void set_color(int color);
};

class Rejilla{
  vector<Casilla> rejilla;
  int color_base;
public:

  Rejilla();

  Rejilla(int color);

  void set_color_base(int color);

  int get_color_base();

  int colorPos(int i, int j);

  void setPos(int i, int j, int color);

  char* write(int i, int j);
};

  Casilla::Casilla(){
    this->set_color(BLANCO);
    this->set_i(0);
    this->set_j(0);
  }

  Casilla::Casilla(int i, int j, int color){
    this->set_color(color);
    this->set_i(i);
    this->set_j(j);
  }

  int Casilla::get_i(){
    return this->i;
  }

  void Casilla::set_i(int i){
    this->i = i;
  }

  int Casilla::get_j(){
    return this->j;
  }

  void Casilla::set_j(int j){
    this->j = j;
  }

  int Casilla::get_color(){
    return this->color;
  }

  void Casilla::set_color(int color){
    this->color = color;
  }

  Rejilla::Rejilla(){
    this->set_color_base(BLANCO);
  }

  Rejilla::Rejilla(int color){
    rejilla.resize(0);
    this->set_color_base(color);
  }

  void Rejilla::set_color_base(int color){
    rejilla.resize(0);
    this->color_base = color;
  }

  int Rejilla::get_color_base(){
    return this->color_base;
  }

  int Rejilla::colorPos(int i, int j){
    bool noencontrado = true;
    for(int a = 0; a < rejilla.size(); a++){
      if(rejilla[a].get_i() ==  i && rejilla[a].get_j() == j){
        return rejilla[a].get_color();
        noencontrado = false;
        break;
      }
    }
    if(noencontrado){
      return this->get_color_base();
    }
  }

  void Rejilla::setPos(int i, int j, int color){
    if(color == this->get_color_base()){
      for(int a = 0; a < rejilla.size(); a++){
        if(rejilla[a].get_i() ==  i && rejilla[a].get_j() == j){
          vector<Casilla> dummy;
          for(int b = 0; b < a; b++){
            dummy.push_back(rejilla[b]);
          }
          for(int b = a + 1; b < rejilla.size(); b++){
            dummy.push_back(rejilla[b]);
          }
          rejilla.clear();
          for(int b = 0; b < dummy.size(); b++){
            rejilla.push_back(dummy[b]);
          }
          break;
        }
      }
    } else{
      bool noencontrado = true;
      for(int a = 0; a < rejilla.size(); a++){
        if(rejilla[a].get_i() ==  i && rejilla[a].get_j() == j){
          rejilla[a].set_color(color);
          noencontrado = false;
          break;
        }
      }
      if(noencontrado){
        rejilla.push_back(Casilla(i, j, color));
      }
    }
  }

  char* Rejilla::write(int i, int j){
    switch (this->colorPos(i, j)) {
      case BLANCO:
        return WHITHE;
        break;
      case NEGRO:
        return BLACK;
        break;
    }
  }
