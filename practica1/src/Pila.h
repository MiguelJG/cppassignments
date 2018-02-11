#include "Vector.h"

template <class T>
class Pila{
public:
  Vector<T> pila;

  Pila(void);

  int _size(void);


  T& top(void);//getset

  void push(T dato);

  T pop(void);

  bool empty(void);
};

