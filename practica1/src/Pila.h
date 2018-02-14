#include "List_Doble.h"
typedef int T;
//template <class T>
class Pila{
public:
  dll_t<T>* pila;

  Pila(void);

  int _size(void);


  T top(void);//getset

  void push(T dato);

  const T pop(void);

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
