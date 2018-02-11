#include "Vector.h"

template <class T>
class Cola{
public:
  Vector<T> cola;

  Cola(void);

  int _size(void);

  void push(T dato);

  T pop(void);

  bool empty(void);
};

