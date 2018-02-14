#pragma once
#include "Nodo.h"

/**
 * \class dll_t
 *
 *
 * \brief Clase que deefine Una lista doblemente enlazada
 *
 * Esta clase es una implementación básica de una lista doblemente enlazada 
 *
 * \author Miguel Jiménez Gomis
 *
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
template <class T>
    class dll_t {
    private:
        dll_node_t<T>* head_;
        dll_node_t<T>* tail_;
        int sz_;

    public:

/** \brief constructor por defecto
  * 
  * Este merodo contruye una lista vacía
  */
        dll_t(void);
   
/** \brief Destructor por defecto
  */
        virtual ~dll_t(void); 

/** \brief insert tail
  * \return inserta un nuevo nodo al final de la lista
  */
	      void insert_tail(dll_node_t<T>*);

/** \brief insert head
  * \return rInserta un nuevo nodo al inicio de la lista
  */
        void insert_head(dll_node_t<T>*);

/** \brief get head
  * \return retorna y elimina el ultimo nodo de la lista
  */
        dll_node_t<T>* extract_tail(void);

/** \brief get head
  * \return retorna y elimina el primer nodo de la lista
  */
        dll_node_t<T>* extract_head(void);

/** \brief get tail
  * \return retorna un acceso al ultimo objeto nodo de la lista
  */
        dll_node_t<T>* get_tail(void);

/** \brief get head
  * \return retorna un acceso al primer objeto nodo de la lista
  */
        dll_node_t<T>* get_head(void);

				
/** \brief Vacío
  * \return bool true si esta vacío
  * 
  * Este metodo indica si la cola está vacía o no
  */
        bool empty(void);

/** \brief Elimina un nodo
  * Dado un puntero a un nodo en concreto, este es eliminado de la lista
  */
        void remove(dll_node_t<T>*);

/** \brief get size
  * \return int numero de elementos en la lista
  */
        int get_size(void);

/** \brief write
  * \return Escribe de manera formateada la lista en el ostream indicado
  */
        ostream& write(ostream& os);
    };


    template <class T>
    dll_t<T>::dll_t(void) :head_(NULL), tail_(NULL), sz_(0) {}

    template <class T>
    dll_t<T>::~dll_t(void) {
        dll_node_t<T>* aux = NULL;
        while (head_ != NULL) {
            aux = head_;
            head_ = head_->get_next();
            delete aux;
            aux = NULL;
        }
        sz_ = 0;
        head_ = NULL;
        tail_ = NULL;
    }

    template <class T>
    bool dll_t<T>::empty(void) {
	    if (head_ == NULL){
	      assert(tail_ == NULL);
	      assert(sz_ == 0);
	      return true;
	    } else 
	      return false;
    }

    template <class T>
    void dll_t<T>::insert_head(dll_node_t<T>* nodo) {
        assert(nodo != NULL);
        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            head_->set_prev(nodo);
            nodo->set_next(head_);
            head_ = nodo;
        }
        sz_++;
    }

    template <class T>
    void dll_t<T>::insert_tail(dll_node_t<T>* nodo) {
        assert(nodo != NULL);
        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            tail_->set_next(nodo);
            nodo->set_prev(tail_);
            tail_ = nodo;
        }
        sz_++;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::extract_tail(void) {
        assert(!empty());
        dll_node_t<T>* aux = tail_;
        tail_ = tail_->get_prev();
        if (tail_ != NULL)
            tail_->set_next(NULL);
        else
            head_ = NULL;
        sz_--;
	      aux->set_next(NULL);
	      aux->set_prev(NULL);
        return aux;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::extract_head(void) {
        assert(!empty());
        dll_node_t<T>* aux = head_;
        head_ = head_->get_next();
        if (head_)
            head_->set_prev(NULL);
        else
            tail_ = NULL;
        sz_--;
	      aux->set_next(NULL);
	      aux->set_prev(NULL);

        return aux;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::get_head(void) {
	    return head_;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::get_tail(void) {
	    return tail_;
    }

    template <class T>
    ostream& dll_t<T>::write(ostream& os) {		
        dll_node_t<T>* aux = head_;
        while (aux != NULL) {
            aux->write(os);
            aux = aux->get_next();
        }

	return os;
    }

    template <class T>
    void dll_t<T>::remove(dll_node_t<T>* nodo) {			
        assert(nodo != NULL);
        if (nodo->get_prev() != NULL)
            nodo->get_prev()->set_next(nodo->get_next());
        else
            head_ = nodo->get_next();
        if (nodo->get_next() != NULL)
            nodo->get_next()->set_prev(nodo->get_prev());
        else
            tail_ = nodo->get_prev();
	      delete nodo;
        sz_--;
    }

    template <class T>
    int dll_t<T>::get_size(void) {
        return sz_;
    }
