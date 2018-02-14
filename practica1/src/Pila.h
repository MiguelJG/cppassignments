#include "List_Doble.h"
typedef int T;

/**Pila
 *
 *
 * \brief Clase que deefine Una pila
 *
 * Esta clase es una implementación básica de una pila
 *
 * \author Miguel Jiménez Gomis
 *
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Pila{
public:
  dll_t<T>* pila;

/** \brief Constructor por defecto
  * 
  * Este metodo instancia un objeto de la clase pila
  */
  Pila(void);

/** \brief _size
  *
  * \return int en el que se encuentra el numero de elementos en la cola
  * 
  */
  int _size(void);

/** \brief top
  *
  * \return T dato que te permite ver el primer dato de la pila
  * 
  */
  T top(void);//getset

/** \brief push
  *
  * \param T dato que es el dato a introducir en el tope de la pila
  * 
  */
  void push(T dato);

/** \brief pop
  *
  * \return T dato qe se almacenaba en el tope de la pila
  * 
  */
  const T pop(void);

/** \brief empty
  *
  * \return bool true si está vacía
  * 
  */
  bool empty(void);
};

  //template <class T>
  Pila::Pila(void){
    pila = new dll_t<T>();
  }

  //template <class T>
  int Pila::_size(void){
    return pila->get_size();
  }

  //template <class T>
  T Pila::top(void){
    return pila->get_tail()->get_data();
  }

  //template <class T>
  void Pila::push(T dato){
    pila->insert_tail(new dll_node_t<T>(dato));
  }

  //template <class T>
  const T Pila::pop(void){
    return  pila->extract_tail()->get_data();
  }

  //template <class T>
  bool Pila::empty(void){
    if(pila->get_size() ==  0)
      return true;
    else
      return false;
  }
