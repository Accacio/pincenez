#include "entry.hpp"


int main(int argc, char *argv[]) {

    std::string path = argv[0];
    path = path.substr(0,path.find_last_of("/\\"));
    cd(path.data());

    Game * myGame = newGame();
    myGame->run();
    delete myGame;
    return 0;
}
