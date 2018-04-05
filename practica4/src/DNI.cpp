#include "DNI.h"

DNI::DNI(void){
    // Generar la matrícula aleatoriamente //
    key_ = rand() % 100000000;
}

DNI::DNI(int dni){
    // Generar la matrícula aleatoriamente //
    key_ = dni;
}

int DNI::get_key(void) const{
    return key_;
}

// conversion de DNI a unsigned long -> type-cast operator
DNI::operator unsigned long() const{
    return (unsigned long)key_;
}

std::ostream& operator<<(std::ostream& os, const DNI& M)
{
    os << M.get_key() << " ";
    return os;
}
