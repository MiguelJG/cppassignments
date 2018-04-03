
#ifndef __MATRICULA__
#define __MATRICULA__

#include <string>
#include <ctime>        // time
#include <cstdlib>      // srand, rand
#include <cmath>        // pow


#include <iostream>

////////////////////////////////////////////////////////////////
//
// EN EL MAIN ANTES DE DECLARAR LAS COSAS:    srand(time(NULL));
//
////////////////////////////////////////////////////////////////

class Matricula
{
    // Se deben sobrecargar las operaciones de comparación requeridas por las
    // plantillas de Tabla<clave> y Celda<clave>

    private:
        std::string      key_; // Concatenación de 4 dígitos y 3 letras
        
    public:
        Matricula(void);
        ~Matricula(){};
        
        std::string get_key(void) const;
        
        operator unsigned long() const;
        friend std::ostream& operator<<(std::ostream& os, Matricula& M);
};

#endif