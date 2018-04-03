#ifndef __TABLA__
#define __TABLA__


#include <vector>


template <class T> class Tabla{
    private:
        std::vector<Celda<T>* >       vCelda_;
        fDispersion<T>*                  fD_;
        fExploracion<T>*                 fE_;
    public:
        Tabla(int nCeldas, int nBloques, int fD, int fE){
            vCelda_.resize(nCeldas);
            for (int i = 0; i < vCelda_.size(); i++){
                vCelda_[i] = new Celda<T>(nBloques);
            }
            fD_ = fDispersion<T>::crearfDispersion(fD, nCeldas);
            fE_ = fExploracion<T>::crearfExploracion(fE, fD, nCeldas);
        }

        ~Tabla(){
            for (int i = 0; i < vCelda_.size(); i++){
                delete vCelda_[i];
            }
            vCelda_.clear();
            delete fD_;
            delete fE_;
        }

        bool buscar (const T& x, int &min, int& max, int& total){
            int comparaciones = 0;
            unsigned indice = fD_->fDispersion<T>::funcion_dispersion(x);
            unsigned indice2 = indice;
            bool fin = false;
            bool insertado = vCelda_[indice]->buscar(x, comparaciones);
            int intentos = 1;
            while (!insertado && !fin){
                intentos++;
                indice2 = (indice + fE_->funcion_exploracion(x, intentos)) % vCelda_.size();
                bool encontrado = vCelda_[indice2]->buscar(x, comparaciones);
                if (indice2 == indice) fin = true;
            }
            if (min == -1) min = comparaciones;
            if (comparaciones > max) max = comparaciones;
            total += comparaciones;
            if (comparaciones < min) min = comparaciones;
            if (fin) return 0;
            else return 1;
        }

        bool insertar (const T& x){
            int indice = fD_->fDispersion<T>::funcion_dispersion(x);
            int indice2 = indice;
            bool fin = false;
            bool insertado = vCelda_[indice]->insertar(x);
            int intentos = 1;
            while (!insertado && !fin){
                intentos++;
                indice2 = (indice + fE_->funcion_exploracion(x, intentos)) % vCelda_.size();
                bool insertado = vCelda_[indice2]->insertar(x);
                if (indice2 == indice) fin = true;
            }
            if (fin) return 0;
            else return 1;
        }
};

#endif
