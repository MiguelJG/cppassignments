#include <iostream>

using namespace std;


//onst int BLANCO = 0;
//const int NEGRO = 1;
const int NORTE = 1;
const int ESTE = 2;
const int SUR = 3;
const int OESTE = 4;

class Hormiga{
  int i;
  int j;
  int dir; //1 N ^, 2 E >, 3 S v, 4 O <
public:

  Hormiga();

  Hormiga(int i, int j, int dir);

  void set_i(int i);

  int get_i();

  void set_j(int j);

  int get_j();

  void set_dir(int dir);

  int get_dir();

  int next_pos(int color);

  char write();
};

Hormiga::Hormiga(){
  this->set_i(0);
  this->set_j(0);
  this->set_dir(NORTE);
}

Hormiga::Hormiga(int i, int j, int dir){
  this->set_i(i);
  this->set_j(j);
  this->set_dir(dir);
}

void Hormiga::set_i(int i){
  this->i = i;
}

int Hormiga::get_i(){
  return this->i;
}

void Hormiga::set_j(int j){
  this->j = j;
}

int Hormiga::get_j(){
  return this->j;
}

void Hormiga::set_dir(int dir){
  /*if(dir < NORTE || dir > OESTE){
    cout << "Direccion no valida, se asigna Norte" << endl;
    this->dir = NORTE;
  } else{*/
    this->dir = dir;
  //}
}

int Hormiga::get_dir(){
  return this->dir;
}

int Hormiga::next_pos(int color){
  if(color == BLANCO){
    if((this->get_dir() - 1 ) == 0){
      this->set_dir(OESTE);
    } else{
      this->set_dir(this->get_dir() - 1);
    }
    switch (this->get_dir()) {
      case NORTE:
        this->set_i(this->get_i() - 1);
        break;
      case ESTE:
        this->set_j(this->get_j() + 1);
        break;
      case SUR:
        this->set_i(this->get_i() + 1);
        break;
      case OESTE:
        this->set_j(this->get_j() - 1);
        break;
    }
    return NEGRO;
  } else if(color == NEGRO){
    if((this->get_dir() + 1 ) == 5){
      this->set_dir(NORTE);
    } else{
      this->set_dir(this->get_dir() + 1);
    }
    switch (this->get_dir()) {
      case NORTE:
        this->set_i(this->get_i() - 1);
        break;
      case ESTE:
        this->set_j(this->get_j() + 1);
        break;
      case SUR:
        this->set_i(this->get_i() + 1);
        break;
      case OESTE:
        this->set_j(this->get_j() - 1);
        break;
    }
    return BLANCO;
  }
}

char Hormiga::write(){
  switch (this->get_dir()) {
    case NORTE:
      return '^';
      break;
    case ESTE:
      return '>';
      break;
    case SUR:
      return 'v';
      break;
    case OESTE:
      return '<';
      break;
  }
}
