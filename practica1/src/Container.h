#include <iostream>

using namespace std;

template<class T> class Container{
  
  virtual T _size();
  
  virtual T& get(int i);//getset

  virtual void push(T dato);

  virtual T pop(void);

  virtual void push_back(T dato);

  virtual T pop_back(void); 
};
