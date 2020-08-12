#ifndef __SPRITEBATCHER_H_
#define __SPRITEBATCHER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "vector2.hpp"
#include "rectangle.hpp"
#include "color.hpp"

enum SpriteEffects
{
None = SDL_FLIP_NONE,
FlipHorizontally = SDL_FLIP_HORIZONTAL,
FlipVertically = SDL_FLIP_VERTICAL
};

class SpriteBatch {
    public:
        SpriteBatch(SDL_Renderer* renderer);
        ~SpriteBatch(){};
        SDL_Renderer* _renderer=NULL;

        void begin(SDL_BlendMode blendMode = SDL_BLENDMODE_NONE);
        void end();

        // void drawString();
        void draw(SDL_Texture* texture,
                  Vector2 position,
                  Rectangle srcRect,
                  Color color,
                  float rotationDeg, Vector2 rotOrigin,Vector2 scale,SpriteEffects effect=SpriteEffects::None);
// Begin (SpriteSortMode sortMode = SpriteSortMode.Deferred, BlendState blendState = null, SamplerState samplerState = null, DepthStencilState depthStencilState = null, RasterizerState rasterizerState = null, Effect effect = null, Matrix? transformMatrix = default(Matrix?));
        // DrawString(Draw.DefaultFont, drawCommands[i].Text, new Vector2(20, screenHeight - 92 - (30 * i)), drawCommands[i].Color);
        SDL_BlendMode _blendMode = SDL_BLENDMODE_NONE;
};

#endif // __SPRITEBATCHER_H_
