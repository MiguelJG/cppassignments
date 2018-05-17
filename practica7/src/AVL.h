#ifndef __ARBOLAVL__

#include "NodoAVL.h"

#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <queue>        // std::queue

using namespace std;

template <class T>
class ArbolAVL{
    private:
        NodoAVL<T>*      raiz_;
    public:
        ArbolAVL(void){
            raiz_ = NULL;
        }

        ~ArbolAVL(void){
            podar(raiz_);
        }

        NodoAVL<T>* buscar(T dato){
            return buscarRama(raiz_, dato);
        }


        friend ostream& operator<<(ostream& os, const ArbolAVL<T>& arbol){
            queue<pair<NodoAVL<T>*, int> > Q;
            NodoAVL<T>* nodo;
            int nivel, nivel_actual = 0;
            Q.push(make_pair(arbol.raiz_, nivel_actual));
            os << '\n' << nivel_actual << ": ";
            while(!Q.empty()){
                pair<NodoAVL<T>*, int> tmp = Q.front();
                Q.pop();
                nivel = get<1>(tmp);
                if ( nivel > nivel_actual){
                    nivel_actual = nivel;  //Incremento de nivel
                    os << '\n' << nivel_actual << ": ";
                }
                NodoAVL<T>* nodo_tmp = get<0>(tmp);
                if (nodo_tmp != NULL){
                    os << *nodo_tmp << " ";
                    Q.push(make_pair(nodo_tmp->get_izq(), nivel_actual+1));
                    Q.push(make_pair(nodo_tmp->get_der(), nivel_actual+1));
                }
                else{
                    os << "[.] ";
                }
            }
            return os;
        }

        void Insertar( T ClaveDada){
            NodoAVL<T>* nuevo = new NodoAVL<T>(ClaveDada);
            bool crece = false;
            inserta_bal(raiz_, nuevo, crece);
        }

        void Eliminar(T clave_dada){
            bool decrece = false;
            elimina_rama( raiz_, clave_dada, decrece);
        }
    private:
        void podar (NodoAVL<T>* nodo){
            if (nodo == NULL) return;
            podar(nodo->get_izq());
            podar(nodo->get_der());
            delete nodo;
            nodo = NULL;
        }

        NodoAVL<T>* buscarRama(NodoAVL<T>* nodo, T dato){
            if (nodo == NULL)
                return NULL;
            if (dato == nodo->get_dato())
                return nodo;
            if (dato < nodo->get_dato())
                return buscarRama(nodo->get_izq(), dato);
            else
                return buscarRama(nodo->get_der(), dato);
        }

        void inserta_bal(NodoAVL<T>* &nodo, NodoAVL<T>* nuevo, bool& crece){
            if (nodo == NULL){
                nodo = nuevo;
                crece = true;
            }
            else if (nuevo->get_dato() < nodo->get_dato()){
                inserta_bal(nodo->get_izq(),nuevo,crece);
                if (crece) insert_re_balancea_izda(nodo, crece);
            } else{
                inserta_bal(nodo->get_der(),nuevo,crece);
                if (crece) insert_re_balancea_dcha(nodo, crece);
            }
        }

        void insert_re_balancea_izda(NodoAVL<T>* &nodo, bool& crece){
            switch (nodo->get_bal()){
                case -1:    nodo->set_bal(0);
                            crece = false;
                            break;
                case 0:     nodo->set_bal(1);
                            break;
                case 1: NodoAVL<T>* nodo1 = nodo->get_izq();
                            if (nodo1->get_bal() == 1)
                                rotacion_II(nodo);
                            else
                                rotacion_ID(nodo);
                            crece = false;
                            break;
            }
        }

        void insert_re_balancea_dcha (NodoAVL<T>* &nodo, bool& crece){
            switch (nodo->get_bal()){
                case 1:     nodo->set_bal(0);
                            crece = false;
                            break;
                case 0:     nodo->set_bal(-1);
                            break;
                case -1:    NodoAVL<T>* nodo1 = nodo->get_der();
                            if (nodo1->get_bal() == -1)
                                rotacion_DD(nodo);
                            else
                                rotacion_DI(nodo);
                            crece = false;
                            break;
            }
        }

        void elimina_rama(NodoAVL<T>* &nodo, T clave_dada, bool& decrece){
            if (nodo == NULL) return;
            if (clave_dada < nodo->get_dato()){
                elimina_rama(nodo->get_izq(),clave_dada,decrece);
                if (decrece)
                    eliminar_re_balancea_izda(nodo,decrece);
            }
            else if (clave_dada > nodo->get_dato()){
                elimina_rama(nodo->get_der(),clave_dada,decrece);
                if (decrece)
                    eliminar_re_balancea_dcha(nodo,decrece);
            }
            else{ // nodo->clave == clave_dada(encontrado)
                NodoAVL<T>* Eliminado = nodo;
                if (nodo->get_izq() == NULL){
                    nodo = nodo->get_der();
                    decrece = true;
                }
                else if (nodo->get_der() == NULL){
                    nodo = nodo->get_izq();
                    decrece = true;
                }
                else{
                    sustituye(Eliminado,nodo->get_izq(),decrece);
                    if (decrece)
                        eliminar_re_balancea_izda(nodo,decrece);
                }
                delete Eliminado;
            }
        }

        void sustituye(NodoAVL<T>* &eliminado, NodoAVL<T>* &sust, bool &decrece){
            if (sust->get_der() != NULL){
                sustituye(eliminado, sust->get_der(), decrece);
                if (decrece)
                    eliminar_re_balancea_dcha(sust, decrece);
            }
            else{
                eliminado->set_dato(sust->get_dato());
                eliminado = sust;
                sust = sust->get_izq();
                decrece = true;
            }
        }

        void eliminar_re_balancea_izda (NodoAVL<T>* &nodo, bool& decrece){
            switch (nodo->get_bal()){
                case -1:{
                    NodoAVL<T>* nodo1 = nodo->get_der();
                    if (nodo1->get_bal() > 0)
                        rotacion_DI(nodo);
                    else{
                        if (nodo1->get_bal() == 0)
                        decrece = false;
                        rotacion_DD(nodo);
                    }
                    break;
                }
                case 0:{
                    nodo->set_bal(-1);
                    decrece = false;
                    break;
                }
                case 1:{
                    nodo->set_bal(0);
                    break;
                }
            }
        }

        void eliminar_re_balancea_dcha (NodoAVL<T>* &nodo, bool& decrece){
            switch (nodo->get_bal()){
                case 1:{
                        NodoAVL<T>* nodo1 = nodo->get_izq();
                        if (nodo1->get_bal() < 0)
                            rotacion_ID(nodo);
                        else{
                            if (nodo1->get_bal() == 0)
                                decrece = false;
                            rotacion_II(nodo);
                        }
                        break;
                }
                case 0:{
                        nodo->set_bal(1);
                        decrece = false;
                        break;
                }
                case -1:{
                        nodo->set_bal(0);
                        break;
                }
            }
        }
        // Rotaciones ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        void rotacion_II (NodoAVL<T>* &nodo){
            NodoAVL<T>* nodo1 = nodo->get_izq();
            nodo->get_izq()  = nodo1->get_der();
            nodo1->get_der() = nodo;
            if (nodo1->get_bal() == 1) {
                nodo->set_bal(0);
                nodo1->set_bal(0);
            }
            else{ // nodo1->bal == 0
                nodo->set_bal(1);
                nodo1->set_bal(1);
            }
            nodo = nodo1;
        }

        void rotacion_DD (NodoAVL<T>* &nodo){
            NodoAVL<T>* nodo1 = nodo->get_der();
            nodo->get_der() = nodo1->get_izq();
            nodo1->get_izq() = nodo;
            if (nodo1->get_bal() == -1){
                nodo->set_bal(0);
                nodo1->set_bal(0);
            }
            else{ // nodo1->bal == 0
                nodo->set_bal(-1);
                nodo1->set_bal(-1);
            }
            nodo = nodo1;
        }

        void rotacion_ID (NodoAVL<T>* &nodo){
            NodoAVL<T>* nodo1 = nodo->get_izq();
            NodoAVL<T>* nodo2 = nodo1->get_der();
            nodo->get_izq() = nodo2->get_der();
            nodo2->get_der() = nodo;
            nodo1->get_der() = nodo2->get_izq();
            nodo2->get_izq() = nodo1;
            if (nodo2->get_bal() == -1)
                nodo1->set_bal(1);
            else
                nodo1->set_bal(0);
            if (nodo2->get_bal() == 1)
                nodo->set_bal(-1);
            else
                nodo->set_bal(0);
            nodo2->set_bal(0);
            nodo = nodo2;
        }

        void rotacion_DI (NodoAVL<T>* &nodo){
            NodoAVL<T>* nodo1 = nodo->get_der();
            NodoAVL<T>* nodo2 = nodo1->get_izq();
            nodo->get_der() = nodo2->get_izq();
            nodo2->get_izq() = nodo;
            nodo1->get_izq() = nodo2->get_der();
            nodo2->get_der() = nodo1;
            if (nodo2->get_bal() == 1)
                nodo1->set_bal(-1);
            else
                nodo1->set_bal(0);
            if (nodo2->get_bal() == -1)
                nodo->set_bal(1);
            else
                nodo->set_bal(0);                
            nodo2->set_bal(0);
            nodo = nodo2;
        }


};

#endif
