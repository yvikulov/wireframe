#include "Engine.hpp"

// Constructor -----------------------------------------------------------------
Engine::Engine(Wireframe & wireframe) : _wireframe(wireframe)
{
    // SDL init ----------------------------------------------------------------
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error(SDL_GetError());

    // Create window -----------------------------------------------------------
    this->_window = SDL_CreateWindow(
        APPLICATION_NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        this->_width,
        this->_height,
        SDL_WINDOW_SHOWN
    );

    if (this->_window == nullptr)
        throw std::runtime_error(SDL_GetError());

    // Create render -----------------------------------------------------------
    this->_render = SDL_CreateRenderer(
        this->_window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    
    if (this->_render == nullptr)
        throw std::runtime_error(SDL_GetError());
}

// Main loop -------------------------------------------------------------------
int Engine::run()
{
    SDL_Event event;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }

        // this->renderWireframe();
    }

    return EXIT_SUCCESS;
}

// Destructor of engine --------------------------------------------------------
Engine::~Engine()
{
    SDL_DestroyRenderer(this->_render);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}
