#ifndef __GAME_H
#define __GAME_H

#include "dict.h"
#include "profile.h"

#define GUESS_MAX 6

class Game {
private:
    Profile profile;
    Dict dict;

    std::string word;
    unsigned guesses;

    bool playing;

public:
    Game(std::string dict);

    inline void fetchWord() { this->word = dict.fetchWord(); }

    void start();
    bool play();
    void print(std::string visible);
    bool setLetter(std::string &visible, char c);
    void reset();
};

#endif
