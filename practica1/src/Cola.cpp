#include "Cola.h"

  template <class T>
  Cola<T>::Cola(void){
    cola = new Vector<T>(0);
  }

  template <class T>
  int Cola<T>::_size(void){
    return cola._size();
  }

  template <class T>
  void Cola<T>::push(T dato){
    cola.push_back(dato);
  }

  template <class T>
  T Cola<T>::pop(void){
    return  cola.pop();
  }

  template <class T>
  bool Cola<T>::empty(void){
    if(cola._size() ==  0)
      return true;
    else
      return false;
  }
