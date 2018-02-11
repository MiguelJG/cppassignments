#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class dll_node_t {
  private:
    dll_node_t<T>* next_;
    dll_node_t<T>* prev_;
    T   data_;
   public:

    dll_node_t();

    dll_node_t(const T& data);

    virtual ~dll_node_t(void);

    void set_next(dll_node_t<T>*);

	  void set_prev(dll_node_t<T>*);

    dll_node_t<T>* get_next(void) const;

	  dll_node_t<T>* get_prev(void) const;

    void set_data(const T& data);

    T get_data(void) const;

    ostream& write(ostream& os) const;

  };
