#include "../include/game.h"

Game::Game(std::string dict) {
    this->dict = Dict(dict);
    fetchWord();
    this->guesses = GUESS_MAX;
    this->playing = true;
}

void Game::start() {
    using std::cout;

    char user;
    while (this->playing) {
        if (play())
            profile.win();
        else
            profile.loose();

        reset();
        profile.save();

        cout << std::endl << "Voulez vous rejouer ? y/n" << std::endl;
        cout << ":";
        std::cin >> user;

        user = toUpper(user);

        while (user != 'N' && user != 'Y') {
            cout << std::endl << user << " Voulez vous rejouer ? y/n" << std::endl;
            cout << ":";
            std::cin >> user;

            user = toUpper(user);
        }

        if (user == 'N')
            this->playing = false;
    }

    cout << std::endl << "Au revoir " << profile.getName() << ". Vous avez " << std::setprecision(5) << profile.getRatio() << "% de victoire." << std::endl;
}

bool Game::play() {
    using std::cout;
    std::string visible("");

    for (size_t i = 0; i < this->word.size(); i++) {
        visible += "_";
    }

    char user_guess;
    while (visible != this->word && this->guesses > 0) {
        print(visible);
        std::cin >> user_guess;

        user_guess = toUpper(user_guess);

        if (!setLetter(visible, user_guess)) {
            this->guesses--;
            cout << "Mauvaise pioche..." << std::endl;
        } else {
            cout << "Bonne pioche !" << std::endl;
        }
    }

    cout << std::endl;
    if (this->guesses <= 0) {
        cout << "Vous avez perdu ! Le mot était " << this->word << std::endl;
        return false;
    } else if (this->word == visible) {
        cout << "Vous avez gagnez ! Le mot était " << this->word << std::endl;
        return true;
    }
    return false;
}

void Game::print(std::string visible) {
    using std::cout;

    cout << "Mot : " << visible << std::endl << std::endl;
    cout << "Il vous reste " << this->guesses << "." << std::endl;
    cout << "Choisissez une lettre :";
}

bool Game::setLetter(std::string &visible, char c) {
    bool ret = false;

    for (size_t i = 0; i < this->word.size(); i++) {
        if (this->word[i] == c) {
            ret = true;
            visible[i] = c;
        }
    }

    return ret;
}

void Game::reset() {
    fetchWord();
    this->guesses = GUESS_MAX;
}
