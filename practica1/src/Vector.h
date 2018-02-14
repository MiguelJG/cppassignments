
#pragma once
#include <iostream>
 using namespace std;

typedef int T;

/**
 * \class dll_t
 *
 *
 * \brief Clase que deefine Un vector dinámico
 *
 * Esta clase es una implementación básica de una lista doblemente enlazada 
 *
 * \author Miguel Jiménez Gomis
 *
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Vector{
  int size;
  T* vector;//puntero para el vector con memoria dinamica

public:

/** \brief Constructor por defecto
  * 
  * Este metodo instancia un objeto de la clase vector
  */
  Vector(int size);

/** \brief _size
  *
  * \return int en el que se encuentra el numero de elementos en el vector
  * 
  */
  int _size(void);

/** \brief resize
  *
  * \param int new size
  * Reestablece el tamaño del vector a uno nuevo
  * 
  */
  void resize(int size);

/** \brief get
  *
  * \return T dato por referencia, es un getset del vector
  * 
  */
  T& get(int i);//getset

/** \brief push
  *
  * \param T dato añade un nuevo dato al inicio
  * 
  */
  void push(T dato);

/** \brief _size
  *
  * \return T dato del inicio del vector y lo elimina
  * 
  */
  T pop(void);

/** \brief push_back
  *
  * \return añade un nuevo dato al final del vector
  * 
  */
  void push_back(T dato);

/** \brief pop_back
  *
  * \return T dato, elimina el ultimo dato del vector
  * 
  */
  T pop_back(void); 
};

  //template <class T>
  Vector::Vector(int size){
    this->size = size;
    vector = new T [this->size];
  }

  /*template <class T>
  Vector<int>::Vector(int size){
    this->size = size;
    vector = new int [this->size];
  }*/

  //template <class T>
  int Vector/*<T>*/::_size(void){
    return this->size;
  }

  //template <class T>
  void Vector/*<T>*/::resize(int size){
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

  //template <class T>
  T& Vector/*<T>*/::get(int i){
    if(i < 0 || i >= this->size)
      return vector[0];
    else
      return vector[i];
  }

  //template <class T>
  void Vector/*<T>*/::push(T dato){
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

  //template <class T>
  T Vector/*<T>*/::pop(void){
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
  
  //template <class T>
  void Vector/*<T>*/::push_back(T dato){
    resize(this->size + 1);
    this->vector[this->size - 1] = dato;
  }

  //template <class T>
  T Vector/*<T>*/::pop_back(void){
    T data = vector[this->size - 1];
    resize(this->size - 1);
    return data;
  }

