#include "DNI.h"

DNI::DNI(void){
      key_ = rand() % 100000000;
}

int DNI::get_key(void) const{
    return key_;
}

// conversion de DNI a unsigned long -> type-cast operator
DNI::operator unsigned long() const{
    return (unsigned long)key_;
}



int DNI::operator<(const DNI& M){
    comp_++;
    unsigned long a = *this;
    unsigned long b = M;
    if (a < b) return 1;
    else return 0;
}

std::ostream& operator<<(std::ostream& os, const DNI& M){
    os << M.get_key();
    return os;
}
