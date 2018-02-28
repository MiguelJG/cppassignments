#include <iostream>

using namespace std;

const int NORTE = 1;
const int ESTE = 2;
const int SUR = 3;
const int OESTE = 4;

/**Hormiga
 *
 * \brief Clase que implementa los objetos hormiga que recorren la rejilla de la maquina de turin y su comportamiento
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Hormiga{
  int i;
  int j;
  int dir;
public:

  /** \brief Contructor por defecto
    *
    * Este metodo instancia una hormiga con sus valores por defecto
    */
  Hormiga();

  /** \brief Contructor
    *  \param int i posicion i de la hormiga
    *  \param int j posicion j de la hormiga
    *  \param int dir direccion en la que se mueve la hormiga
    * Este metodo instancia una hormiga con las diferentes valores pasado por parametro
    */
  Hormiga(int i, int j, int dir);

  /** \brief set_i
    *
    * |param  int i valor de la posicion i
    */
  void set_i(int i);

  /** \brief get_i
    *
    * \return int  valor de la posicion i
    */
  int get_i();

  /** \brief set_j
    *
    * |param  int j valor de la posicion j
    */
  void set_j(int j);

  /** \brief get_j
    *
    * \return int  valor de la posicion j
    */
  int get_j();

  /** \brief set_dir
    *
    * |param  int dir valor de la direccion
    */
  void set_dir(int dir);

  /** \brief get_dir
    *
    * \return int  valor de la direccion
    */
  int get_dir();

  /** \brief next_pos
    *
    * \return int  valor del color al que se ha actualizado la casilla en la que estaba
    * \param int color Color de la casilla en la que está actualmente
    * Este metodo se la pasa el color de una casilla y la hormiga, en funcion de este color, actualiza su estado (posicon y direccion) y Retorna
    * el color al que se ha de modificar la casilla anterior
    */
  int next_pos(int color);
  /** \brief Write
    *
    * \return char  caracter que representa la direccion de la  hormiga
    * Este metodo retorna el caracter que representa la direccion de la hormiga
    */
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
    this->dir = dir;
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
