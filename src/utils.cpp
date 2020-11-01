#include "../include/utils.h"

Random::Random(unsigned seed) {
    if (seed == 0) {
        this->seed = time(NULL);
        srand(this->seed);
    }
    else {
        this->seed = seed;
        srand(seed);
    }
}

char toUpper(char c) {
    if (c >= 97 && c <= 122) {
        c -= 32;
    }
    return c;
}
