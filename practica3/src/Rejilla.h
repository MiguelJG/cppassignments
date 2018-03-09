#pragma once
#include <iostream>
#include <vector>

using namespace std;
//https://misc.flogisoft.com/bash/tip_colors_and_formatting

#define WHITHE "\x1B[107m\x1B[30m" //colores
#define BLACK "\x1B[40m\x1B[97m"
#define DEFAULT "\x1B[39m\x1B[49m"
#define PINK "\e[45m\x1B[30m"
#define BLUE "\e[44m\x1B[30m"
const int BLANCO = 0;
const int NEGRO = 1;
const int AZUL = 2;
const int ROSA = 3;

/**Casilla
 *
 * \brief Clase que implementa las diferentes casillas del tablero para poder hacer una matriz escasa
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Casilla{
  int color;
  int i;
  int j;
public:

  /** \brief Contructor por defecto
    *
    * Este metodo instancia una casilla con sus valores por defecto
    */
  Casilla();

  /** \brief Contructor
    *  \param int i posicion i de la casilla
    *  \param int j posicion j de la casillas
    *  \param int color color de la casilla
    * Este metodo muestra por la salida estandar el estado actual de la maquinas
    */
  Casilla(int i, int j, int color);

  /** \brief get_i
    *
    * \return int  valor de la posicion i
    */
  int get_i();

  /** \brief set_i
    *
    * |param return int i valor de la posicion i
    */
  void set_i(int i);

  /** \brief get_j
    *
    * \return int  valor de la posicion j
    */
  int get_j();

  /** \brief set_j
    *
    * |param return int j valor de la posicion j
    */
  void set_j(int j);

  /** \brief get_color
    *
    * \return int  color de la casilla
    */
  int get_color();

  /** \brief set_color
    *
    * \param return int color valor del color de la casilla
    */
  void set_color(int color);
};

/**Rejilla
 *
 * \brief Clase que implementa la rejilla en la que se llevará a cabo la simulacion de la maquina de turing representada como una matriz escasa
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Rejilla{
  vector<Casilla> rejilla;
  int color_base;

  /** \brief set_color_base
    *
    * \param in color
    * Establece el color base de la rejilla
    */
  void set_color_base(int color);

  /** \brief get_color_base
    *
    * \return int color
    * Retorna el valor del color base de la rejilla
    */
  int get_color_base();
public:

  /** \brief Contructor por defecto
    *
    * Este metodo instancia una rejill con sus valores por defecto
    */
  Rejilla();

  /** \brief Contructor
    *
    * \param int colore
    *  Este metodo instancia una rejilla con un color base determinado
    */
  Rejilla(int color);

  /** \brief colorPos
    *
    * \param int i valor de la posicion i
    * \param int j valor de la posicion j
    * \return int color de la posicion
    * Este metodo retorna el color de una posicion dad de la rejilla
    */
  int colorPos(int i, int j);

  /** \brief setPos
    *
    * \param int i valor de la posicion i
    * \param int j valor de la posicion j
    * \param int color de la posicion
    * Este metodo establece el color de una posicion dad de la rejilla
    */
  void setPos(int i, int j, int color);

  /** \brief Write
    *
    * \param int i valor de la posicion i
    * \param int j valor de la posicion j
    * \return char* cadena de caracteres que representa la posicion indicada
    * Este metodo retorna la cadena que representala posicon indicada
    */
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
      case AZUL:
        return BLUE;
        break;
      case ROSA:
        return PINK;
        break;
    }
  }
