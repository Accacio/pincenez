#include <iostream>
#include <string>

#include "engine.hpp"

class Sandbox : public Game {
    public:
        Sandbox() {

        }

        ~Sandbox(){

        }
};

Game * newGame(){
    return new Sandbox();
}
