#include "spritebatch.hpp"

SpriteBatch::SpriteBatch(SDL_Renderer* renderer){
    _renderer = renderer;
}

void SpriteBatch::begin(SDL_BlendMode blendMode){
    _blendMode = blendMode;
    // SDL_RenderClear( _renderer );
};
void SpriteBatch::end(){
    SDL_RenderPresent( _renderer );
}
/** srcRect Empty equal all the texture */
void SpriteBatch::draw(SDL_Texture* texture,Vec2 position,Rectangle srcRect,Color color, float rotationDeg, Vec2 rotOrigin,Vec2 scale,SpriteEffects effect){

    if (srcRect==Rectangle::Empty()){
        SDL_QueryTexture(texture, NULL, NULL, &srcRect._width, &srcRect._height);
    }
    SDL_Rect srcrect;
    SDL_Rect dstrect;
    srcrect = {(int) srcRect._x,(int) srcRect._y, (int) srcRect._width,(int) srcRect._height};
    dstrect = {(int) position._x,(int) position._y, (int) (srcRect._width*scale._x),(int) (srcRect._height*scale._y)};
    SDL_SetTextureColorMod( texture, color._r, color._g, color._b);
    SDL_SetTextureBlendMode( texture, _blendMode);
    SDL_SetTextureAlphaMod(texture, color._a);
    SDL_Point center = { (int) rotOrigin._x, (int) rotOrigin._y };
    SDL_RenderCopyEx( _renderer, texture, &srcrect,  &dstrect ,rotationDeg, &center,(SDL_RendererFlip) effect);
};
