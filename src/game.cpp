
#include "game.hpp"


const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "   ourColor = aColor;\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
// "in vec4 vertexColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(ourColor,1.0);\n"
"}";
Game::Game(){
    // PCNLOG("load");
    // LOG("load");
    // Go to execution path
    timeSec = 0;
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
    window = SDL_CreateWindow( "My game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    if( window == NULL ) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        std::exit(-1);
    }
    // renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    // if( renderer == NULL ) {
    //     printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
    //     std::exit(-1);
    // }
    context = SDL_GL_CreateContext(window);

    // Set Vsync
    SDL_GL_SetSwapInterval(1);

    // unsigned int vertexShader;
    // vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // glCompileShader(vertexShader);

    // unsigned int fragmentShader;
    // fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // glCompileShader(fragmentShader);

    // shaderProgram = glCreateProgram();
    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragmentShader);
    // glLinkProgram(shaderProgram);
    // glDeleteShader(vertexShader);
    // glDeleteShader(fragmentShader);

    // glUseProgram(shaderProgram);

};

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( window );
    SDL_Quit();
};

void Game::draw() {

    // Clear screen
    // glViewport(0, 0, 200, 300);
    // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT);

    // glUseProgram(shaderProgram);
    // uint32_t currentTime = SDL_GetTicks();
    // if (currentTime > timeSec + 1000) {
    //     timeSec = currentTime;
    // }
    // float greenValue = (sin((float) currentTime/1000))/2.0f+0.5f;
    // int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    // glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

    // glUseProgram(shaderProgram);

    float vertices[] = {
    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
    0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
};
    unsigned int indices[] = {
    0,1,2,

};

    // unsigned int VAO;
    // glGenVertexArrays(1, &VAO);
    // glBindVertexArray(VAO);

    // unsigned int VBO;
    // glGenBuffers( 1, &VBO );
    // unsigned int EBO;
    // glGenBuffers( 1, &EBO );

    // // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // // Binding vertices array to elementbuffer
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // // Binding indice array to elementbuffer
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    // // enable attribute with location 0
    // glEnableVertexArrayAttrib(VAO, 0);

    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    // // enable attribute with location 1
    // glEnableVertexArrayAttrib(VAO, 1);


    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    // float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // // unsigned int texture2;
    // // glGenTextures(1, &texture2);
    // // glBindTexture(GL_TEXTURE_2D, texture2);

    // // glTexImage2D(GL_TEXTURE_2D, 0, GL_RBA, , GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)

    // glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
    // glBindVertexArray(0);


    SDL_GL_SwapWindow(window);

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
    // SDL_RenderClear(renderer);

    //Load image at specified path
    texture = MTexture::fromFile(renderer, "Content/graphics/preview.jpg");

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
