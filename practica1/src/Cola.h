#include "List_Doble.h"

//template <class T>
class Cola{
public:
  dll_t<T>* cola;

  Cola(void);

  int _size(void);

  void push(T dato);

  T pop(void);

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
