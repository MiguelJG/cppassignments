#ifndef __NODOAVL__
#define __NODOAVL__

#include <iostream>
using namespace std;

template <class T>
class NodoAVL{
    private:
        T               dato_;
        NodoAVL<T>*     izq_;
        NodoAVL<T>*     der_;
        int             bal_;
    public:
    NodoAVL(T dato){
        dato_ = dato;
        izq_  = NULL;
        der_  = NULL;
        bal_  = 0;
    }
    ~NodoAVL(void){
        /*
        if (izq_ != NULL)   delete izq_;
        if (der_ != NULL)   delete der_;
        */
    }

    void set_bal(int bal){
        bal_ = bal;
    }

    void set_dato(T dato){
        dato_ = dato;
    }

    T get_dato(void) const{
        return dato_;
    }

    NodoAVL<T>*& get_izq(void){
        return izq_;
    }

    NodoAVL<T>*& get_der(void){
        return der_;
    }

    int get_bal(void){
        return bal_;
    }


    void insertar_izq(NodoAVL<T> dato){
        bal_ += 1;
        *izq_ = dato;
    }

    void insertar_der(NodoAVL<T> dato){
        bal_ -= 1;
        *der_ = dato;
    }

    friend std::ostream& operator<<(std::ostream& os, const NodoAVL<T>& nodo){
        os << nodo.get_dato();
        return os;
    }

};

#endif
