#ifndef __PROFILE_H
#define __PROFILE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "utils.h"

class Profile {
private :
    std::string name;

    unsigned long wins;
    unsigned long games;

public :
    Profile();
    Profile(std::string save);

    inline std::string getName() const { return this->name; }
    double getRatio();
    inline void win() { wins++; games++; }
    inline void loose() { games++; }

    void print();
    void save();
    void load(std::string save);
};

bool fileExist(std::string path);

#endif
