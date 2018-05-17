#ifndef __DNI__
#define __DNI__

#include <string>
#include <ctime>        // time
#include <cstdlib>      // srand, rand
#include <cmath>        // pow
#include <iostream>


class DNI{
    private:
        int      key_;
    public:
        static int comp_;

        DNI(void);
        ~DNI(){};

        int get_key(void) const;

        operator unsigned long() const;

        int operator<(const DNI& M);

        friend std::ostream& operator<<(std::ostream& os, const DNI& M);
};

#endif
