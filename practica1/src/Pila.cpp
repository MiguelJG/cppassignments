#include "Pila.h"

  template <class T>
  Pila<T>::Pila(void){
    pila = new Vector<T>(0);
  }

  template <class T>
  int Pila<T>::_size(void){
    return pila._size();
  }

  template <class T>
  T& Pila<T>::top(void){
    return pila.get(pila._size() - 1);
  }

  template <class T>
  void Pila<T>::push(T dato){
    pila.push_back(dato);
  }

  template <class T>
  T Pila<T>::pop(void){
    return  pila.pop_back();
  }

  template <class T>
  bool Pila<T>::empty(void){
    if(pila._size() ==  0)
      return true;
    else
      return false;
  }
