#ifndef __GAME_H_
#define __GAME_H_

#include <iostream>

#ifdef _WIN32
#include <direct.h>
// MSDN recommends against using getcwd & chdir names
#define cwd _getcwd
#define cd _chdir
#else
#include "unistd.h"
#define cwd getcwd
#define cd chdir
#endif



#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "spritebatch.hpp"
#include "mtexture.hpp"

class Game {
    public:

        Game();
        virtual ~Game(){
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow( window );
            SDL_Quit();
        };


        void update();
        void draw();
        void run();
        void loadContent();
        void unloadContent(){};
        void initialize(){};

        // void onExit(){};
        void exit(){
            unloadContent();
            // onExit();
            active = false;
        };

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* screenSurface;
        SDL_Surface* optimizedSurface = NULL;
        MTexture texture;

        //Screen dimension constants
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

        SpriteBatch spritebatch=NULL;
    private:
        bool active = true;
};


#endif // __GAME_H_
