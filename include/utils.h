#ifndef __UTILS_H
#define __UTILS_H

#include <ctime>
#include <cstdlib>

class Random {
private :
    unsigned seed;

public :
    Random(unsigned seed = 0);

    inline unsigned gen(int max) { return rand() % max; }

};

char toUpper(char c);

#endif
