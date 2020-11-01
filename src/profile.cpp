#include "../include/profile.h"

Profile::Profile() {
    using std::cout;

    this->wins = 0;
    this->games = 0;

    cout << "Choisissez votre pseudo :";
    std::cin >> this->name;

    std::string path("DATA/");
    path += this->name;
    path += ".save";

    char user;
    if (fileExist(path)) {
        cout << "Ce profil existe déjà." << std::endl;
        cout << "Voulez vous le charger ou le supprimer ? c/s" << std::endl;
        cout << ":";

        std::cin >> user;
        user = toUpper(user);
        while (user != 'C' && user != 'S') {
            cout << "Voulez vous le charger ou le supprimer ? c/s" << std::endl;
            cout << ":";

            std::cin >> user;
            user = toUpper(user);
        }

    }

    cout << std::endl;

    if (user == 'C')
        load(path);

    if (user == 'S')
        save();
}

Profile::Profile(std::string save) {
    load(save);
}

double Profile::getRatio() {
    double ratio;
    ratio = static_cast<double>(this->wins) / static_cast<double>(this->games);

    return ratio * 100;
}

void Profile::print() {
    using std::cout;

    cout << this->name << " : " << this->wins << "/" << this->games << std::endl;
}

void Profile::save() {
    std::ofstream fsave;

    std::string path("DATA/");
    path += this->name;
    path += ".save";

    fsave.open(path);

    fsave << this->name << std::endl
        << this->wins << std::endl
        << this->games;

    fsave.close();
}

void Profile::load(std::string save) {
    std::ifstream fsave;
    fsave.open(save);

    fsave >> this->name;
    fsave >> this->wins;
    fsave >> this->games;

    fsave.close();
}

bool fileExist(std::string path) {
    std::ifstream file;
    file.open(path, std::ios::in);

    bool ret = file.good();

    file.close();

    return ret;
}
