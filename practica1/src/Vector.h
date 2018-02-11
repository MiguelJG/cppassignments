//#include "Container.h"
#pragma once
#include <iostream>
 using namespace std;
template<class T>
//class Vector : public Container<T>{
class Vector{
  int size;
  T* vector;//puntero para el vector con memoria dinamica

public:
  Vector(int size);

  int _size(void);

  void resize(int size);

  T& get(int i);//getset

  void push(T dato);

  T pop(void);

  void push_back(T dato);

  T pop_back(void); 
};
