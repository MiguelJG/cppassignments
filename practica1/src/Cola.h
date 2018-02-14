#include "List_Doble.h"

/**
 * \class Cola
 *
 *
 * \brief Clase que deefine Una cola FIFO
 *
 * Esta clase es una implementación básica de las colas FIFO mediante una lista doblemente enlazada 
 *
 * \note Se podrían añadir muchos mas metodos pero tiene las funcionalidades básicas
 *
 * \author Miguel Jiménez Gomis
 *
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Cola{
public:
  dll_t<T>* cola; ///lista en la que se implementa la cola

/** \brief Constructor por defecto
  * 
  * Este metodo instancia un objeto de la clase cola 
  */
  Cola(void);

/** \brief _size
  *
  * \return int en el que se encuentra el numero de elementos en la cola
  * 
  */
  int _size(void);

/** \brief Push
  * \param T dato dato de tipo predefinido que se quiere añadir a la cola
  * 
  */
  void push(T dato);

/** \brief pop
  * \return Dato del tipo T predefinido
  * Este metodo elimina el primer elemento de la cola y retorna el dato que almacenaba
  */
  T pop(void);

/** \brief Vacío
  * \return bool true si esta vacío
  * 
  * Este metodo indica si la cola está vacía o no
  */
  bool empty(void);
};


  //template <class T>
  Cola::Cola(void){
    cola = new dll_t<int>();
  }

  //template <class T>
  int Cola::_size(void){
    return cola->get_size();
  }

  //template <class T>
  void Cola::push(T dato){
    cola->insert_tail(new dll_node_t<T>(dato));
  }

  //template <class T>
  T Cola::pop(void){
    return  cola->extract_head()->get_data();
  }

  //template <class T>
  bool Cola::empty(void){
    if(cola->get_size() ==  0)
      return true;
    else
      return false;
  }
