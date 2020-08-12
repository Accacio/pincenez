#ifndef __ENTRY_H_
#define __ENTRY_H_


#include "game.hpp"

extern Game * newGame();

int main(int argc, char *argv[]) {

    std::string path = argv[0];
    path = path.substr(0,path.find_last_of("/\\"));
    cd(path.data());

    Game * myGame = newGame();
    myGame->run();
    delete myGame;
    return 0;
}

#endif // __ENTRY_H_
