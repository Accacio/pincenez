#include "game.hpp"

Game::Game(){
    // Go to execution path
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        std::exit(-1);
    }
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        std::exit(-1);
    }
    //Create window
    window = SDL_CreateWindow( "", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL ) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        std::exit(-1);
    }
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( renderer == NULL ) {
        printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
        std::exit(-1);
    }

};

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( window );
    SDL_Quit();
};

void Game::draw() {
    // Clear screen
    spritebatch.begin();

    texture.draw(spritebatch, Vector2(2,2));

    spritebatch.end();

}
void Game::update() {
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:
                exit();
                break;
            default:
                break;
        }
    }
}

void Game::loadContent(){
    // move to constructor
    spritebatch = SpriteBatch(renderer);
    SDL_SetRenderDrawColor(renderer, 0x69,0x95,0xED,0xFF);
    SDL_RenderClear(renderer);

    //Load image at specified path
    texture = MTexture::fromFile(renderer, "Content/graphics/preview.png");

}
void Game::run(){
    initialize();
    loadContent();
    while(active){
        update();
        draw();
        // std::cout<< "Running " << std::endl;
    }
};
