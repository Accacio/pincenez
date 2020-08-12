#ifndef __MTEXTURE_H_
#define __MTEXTURE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "rectangle.hpp"
#include "vector2.hpp"
#include "spritebatch.hpp"


class MTexture {
    public:
        MTexture();
        MTexture(SDL_Texture * texture,std::string filename = "",SDL_Renderer * renderer=NULL);

        virtual ~MTexture();

        static MTexture fromFile(SDL_Renderer * renderer, std::string const & path);

        SDL_Texture * _texture = NULL;
        SDL_Renderer * _renderer = NULL;

        Rectangle ClipRect = Rectangle::Empty();
        Vector2 DrawOffset = Vector2::Zero();
        int _width;
        int _height;
        Vector2 _center = Vector2::Zero();
        int _leftUV;
        int _rightUV;
        int _topUV;
        int _bottomUV;
        // void draw(SpriteBatch spriteBatch);
        void draw(SpriteBatch spriteBatch,Vector2 position);

    private:
        void setUtil();

};



#endif // __MTEXTURE_H_
