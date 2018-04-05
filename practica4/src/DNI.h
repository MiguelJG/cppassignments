
#ifndef __DNI__
#define __DNI__

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

class DNI{
    private:
        int      key_;
    public:
        DNI(void);
        DNI(int dni);
        ~DNI(){};
        int get_key(void) const;
        operator unsigned long() const;
        friend std::ostream& operator<<(std::ostream& os, DNI& M);
};

#endif
