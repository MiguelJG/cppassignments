#include "Vector.h"
  
  template <class T>
  Vector<T>::Vector(int size){
    this->size = size;
    vector = new T [this->size];
  }

  template <class T>
  int Vector<T>::_size(void){
    return this->size;
  }

  template <class T>
  void Vector<T>::resize(int size){
    T* dummy = new T [this->size];
    for(int i = 0; i < (this->size); ++i){
      dummy[i] =  this->vector[i];
    }
    delete[] vector;
    vector = new T [size];
    for(int i = 0; i < size; ++i){
      if(i < this->size)
        vector[i] =  dummy[i];
      else
        vector[i] =  0;
    }
    this->size = size;
  }

  template <class T>
  T& Vector<T>::get(int i){
    if(i < 0 || i >= this->size)
      return vector[0];
    else
      return vector[i];
  }

  template <class T>
  void Vector<T>::push(T dato){
    T* dummy = new T [this->size];
    for(int i = 0; i < this->size; ++i){
      dummy[i] =  this->vector[i];
    }
    delete[] vector;
    vector = new T [this->size + 1];
    for(int i = 1; i < size; ++i){
      if(i < this->size)
        this->vector[i] =  dummy[i];
      else
        this->vector[i] =  0;
    }
    this->size = size + 1;
    vector[0] = dato;
  }

  template <class T>
  T Vector<T>::pop(void){
    T dato = vector[0];
    T* dummy = new T [this->size];
    for(int i = 0; i < this->size; ++i){
      dummy[i] =  this->vector[i];
    }
    delete[] vector;
    vector = new T [this->size - 1];
    for(int i = 1; i < this->size - 1; ++i){
        this->vector[i - 1] =  dummy[i];
    }
    this->size = this->size - 1;
    return dato;
  }
  
  template <class T>
  void Vector<T>::push_back(T dato){
    resize(this->size + 1);
    this->vector[this->size - 1] = dato;
  }

  template <class T>
  T Vector<T>::pop_back(void){
    T data = vector[this->size - 1];
    resize(this->size - 1);
    return data;
  }

