#ifndef __GAME_H_
#define __GAME_H_

#include <iostream>

// #define GL_GLEXT_PROTOTYPES
// #include <GL/gl.h>
// #include <GL/glext.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Log.hpp"
#include "spritebatch.hpp"
#include "mtexture.hpp"

class Game {
    public:
        Game();
        virtual ~Game();

        virtual void update();
        virtual void draw();
        virtual void run();
        virtual void loadContent();
        void unloadContent(){};
        void initialize(){};

        uint32_t timeSec;
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
        SDL_GLContext context;

        unsigned int shaderProgram;
        //Screen dimension constants
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

        SpriteBatch spritebatch=NULL;
    private:
        bool active = true;
};


#endif // __GAME_H_
