#ifndef __FDISPERSION__
#define __FDISPERSION__

#include <cstdlib>
#include <iostream>
// Clase padre
template <class T>
class fDispersion {
    protected:
        unsigned nCeldas_;
    public:
        fDispersion(unsigned nCeldas) {
          nCeldas_ = nCeldas;
        }

        virtual unsigned h(T clave) = 0;

        unsigned funcion_dispersion (const T& clave){
            return (h(clave) % nCeldas_);
        }

        static fDispersion<T>* crearfDispersion (unsigned tipo, unsigned nCeldas);
};


// Hijo módulo
template <class T>
class FDModulo : public fDispersion<T>{
    public:
        FDModulo(unsigned nCeldas):fDispersion<T>(nCeldas){};
        unsigned h(T clave){
            return (clave % (fDispersion<T>::nCeldas_));
        }
};


// Hijo suma
template <class T>
class FDSuma : public fDispersion<T>{
    public:
        FDSuma(unsigned nCeldas):fDispersion<T>(nCeldas){};
        unsigned h(T clave){
            unsigned long claveUnsigned = clave;
            unsigned pos = 0;
            while (claveUnsigned > 0){
                unsigned y = claveUnsigned % 10;
                pos += y;
                claveUnsigned /= 10;
            }
            return pos;
        }
};

// Hijo pseudo-aleatorio
template <class T>
class FDAleatorio : public fDispersion<T>{
    public:
        FDAleatorio(unsigned nCeldas):fDispersion<T>(nCeldas){};
        unsigned h(T clave){
            unsigned long claveUnsigned = clave;
            srand(claveUnsigned);
            unsigned a = rand() % 10000;
            return a;
        }
};

template<class T>
fDispersion<T>* fDispersion<T>::crearfDispersion (unsigned tipo, unsigned nCeldas){
    fDispersion<T>* P;
    switch (tipo){
        case 1:
            P = new FDModulo<T>(nCeldas);
            break;
        case 2:
            P = new FDSuma<T>(nCeldas);
            break;
        case 3:
            P = new FDAleatorio<T>(nCeldas);
            break;
        default:
            std::cerr << "Error. fDispersion. Tipo no reconocido " << tipo << std::endl;
            break;
    }
    return P;
}

#endif
