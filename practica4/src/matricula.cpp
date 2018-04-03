#include "matricula.h"

Matricula::Matricula(void)
{
    // Generar la matrícula aleatoriamente //
    
    key_.resize(7);
    
    //4 primeros dígitos
    for(int i=0; i<4; i++)
        key_[i] = '0' + rand()%10;
        
    //3 caracteres
    for (int i=4; i<key_.size();i++)
        key_[i] = 'A' + rand()%26;
    
}

std::string Matricula::get_key(void) const
{
    return key_;
}

// conversion de Matricula a unsigned long -> type-cast operator
Matricula::operator unsigned long() const
{
    unsigned long num = 0;
    
    for (int i=0; i<key_.size(); i++)
    {
        
        num +=  key_[i] * pow(90,i);
        
        /*
        unsigned long a = key_[i] * pow(90,i);
        std::cout << a << std::endl;
        */
    }
    
    return num;
}

std::ostream& operator<<(std::ostream& os, const Matricula& M)
{
    os << M.get_key() << " ";
    return os;
}