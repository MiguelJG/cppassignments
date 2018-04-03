#ifndef __FEXPLORACION__
#define __FEXPLORACION__

#include <cstdlib>
#include <iostream>
#include <ctime>        // time

// Clase padre
template <class T>
class fExploracion {
    public:
        virtual int funcion_exploracion(T clave, int& intento) = 0;

        static fExploracion* crearfExploracion(int tipo, int disp, int celdas);
};

// Hijo Lineal || DONE
template <class T>
class FELineal : public fExploracion<T>{
    private:
        int celdas_;
    public:
        FELineal(int celdas){
          celdas_ = celdas;
        }

        int funcion_exploracion(T clave, int& intento) {
          return (intento);
        }
};

// Hija Cuadrática || DONE
template <class T>
class FECuadratica : public fExploracion<T>{
    private:
        int celdas_;
    public:
        FECuadratica(int celdas){
           celdas_ = celdas;
        }

        int funcion_exploracion(T clave, int& intento) {
           return ((intento*intento));
        }
};

// Hija DispersiónDoble
template <class T>
class FEDispresionDoble : public fExploracion<T>{
    private:
        int disp_;
        int celdas_;
    public:
        FEDispresionDoble(int disp, int celdas){
          disp_ = disp;
          celdas_ = celdas;
        }

        int funcion_exploracion(T clave, int& intento){
            fDispersion<T>* P = fDispersion<T>::crearfDispersion(disp_,celdas_);
            int pos = P->h(clave);
            pos *= intento;
            delete P;
            return (pos);
        }
};

// Hija reDispersión
template <class T>
class FERedispersion : public fExploracion<T>{
    private:
        int celdas_;
    public:
        FERedispersion(int celdas){
          srand(1996);
          celdas_ = celdas;
        }

        int funcion_exploracion(T clave, int& intento){
            return (rand());
        }
};

////////////////////////////////////////////////////////////////////////////////

template<class T>
fExploracion<T>* fExploracion<T>::crearfExploracion (int tipo, int disp, int nCeldas){
    fExploracion<T>* P;
    switch (tipo){
        case 1:
            P = new FELineal<T>(nCeldas);
            break;
        case 2:
            P = new FECuadratica<T>(nCeldas);
            break;
        case 3:
            disp = (disp + 1) % 4;
            P = new FEDispresionDoble<T>(disp, nCeldas);
            break;
        case 4:
            P = new FERedispersion<T>(nCeldas);
            break;
        default:
            std::cerr << "Error. fExploracion. Tipo no reconocido " << tipo << std::endl;
            break;
    }
    return P;
}

#endif
