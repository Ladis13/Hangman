#include "../include/dict.h"

Dict::Dict() {
    this->nline = 0;
}

Dict::Dict(std::string dict) {
    this->dict = dict;
    this->nline = 0;

    std::fstream fdict;
    fdict.open(dict, std::fstream::in);

    std::string line;
    this->nline = 0;

    while (std::getline(fdict, line)) {
        this->nline++;
    }

    fdict.close();
}

std::string Dict::fetchWord() {
    std::fstream fdict;
    fdict.open(dict, std::fstream::in);

    Random rand;
    unsigned r = rand.gen(this->nline);

    std::string word;
    for (size_t i = 0; i < r; i++) {
        getline(fdict, word);
    }

    fdict.close();

    word.erase(word.end() - 1, word.end());
    return word;
}
