#include "mtexture.hpp"

MTexture MTexture::fromFile(SDL_Renderer * renderer, std::string const & filename){
   
    SDL_Surface* loadedSurface = IMG_Load( filename.data() );
    PCNLOG_DEBUG(filename.data(), " loaded ");
    SDL_Texture * newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface( loadedSurface );
    return MTexture(newTexture, filename,renderer);
}

MTexture::MTexture() {

}

MTexture::~MTexture() {
}

MTexture::MTexture(SDL_Texture * texture, std::string filename,SDL_Renderer * renderer)
{
    _texture = texture;
    _renderer = renderer;
    // AtlasPath = null;
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    ClipRect = Rectangle(0, 0, w, h);
    DrawOffset = Vec2::Zero();
    _width = ClipRect._width;
    _height = ClipRect._height;
// TODO filewatcher
// #if DEBUG
//     if(filename!="")
//     {
//         watcher = new FileSystemWatcher(Path.GetDirectoryName(filename));
//         Console.WriteLine(filename);
//         watcher.Changed += OnChanged;
//         watcher.Filter = Path.GetFileName(filename);
//         watcher.EnableRaisingEvents = true;
//     }
// #endif
    setUtil();
}
void MTexture::setUtil()
{
    int w,h;
    SDL_QueryTexture(_texture, NULL, NULL, &w, &h);
    _center = Vec2(_width, _height) * 0.5f;
    _leftUV = ClipRect.left() / (float)w;
    _rightUV = ClipRect.right() / (float)w;
    _topUV = ClipRect.top() / (float)h;
    _bottomUV = ClipRect.bottom() / (float)h;
}

void MTexture::draw(SpriteBatch spriteBatch,Vec2 position){
  spriteBatch.draw(_texture, position, ClipRect, Color::White(), 0, -DrawOffset,Vec2::Unit());
}
