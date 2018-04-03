#ifndef __CELDA__
#define __CELDA__

#include <vector>

template <class T>
class Celda{
    private:
        std::vector<T*>      bloque_;
        unsigned             top_;
    public:

        Celda(int nBloques){
            bloque_.resize(nBloques);
            top_ = 0;
        }

        ~Celda(){
            for (int i = 0; i < bloque_.size(); i++){
                delete bloque_[i];
            }
            bloque_.clear();
        }

        bool buscar (const T& x, int& comparaciones){
            for (int i = 0; i < top_; i++){
                comparaciones++;
                if (x == *bloque_[i])
                    return 1;
            }
            return 0;
        }

        bool insertar (const T& x){
            if (top_ < bloque_.size()){
                bloque_[top_] = new T(x);
                top_++;
                return 1;
            }
            else return 0;
        }
};

#endif
