#ifndef __DICT_H
#define __DICT_H

#include <iostream>
#include <fstream>
#include <string>

#include "utils.h"

class Dict {
private:
    std::string dict;
    unsigned long nline;

public:
    Dict();
    Dict(std::string dict);

    std::string fetchWord();
};

#endif
