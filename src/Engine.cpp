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
        this->_start_x = (this->_width - this->_distance_x * this->_wireframe.getRow()) / 2;
        this->_start_y = (this->_height - this->_distance_y * this->_wireframe.getColumn()) / 2;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }
        /* Set black background */
        SDL_SetRenderDrawColor(this->_render, 0x0, 0x0, 0x0, 0x0);
        SDL_RenderClear(this->_render);

        this->renderWireframe();

        SDL_RenderPresent(this->_render);
    }

    return EXIT_SUCCESS;
}

// Render the wireframe grid ---------------------------------------------------
void Engine::renderWireframe(void)
{
    int x = this->_start_x;
    int y = this->_start_y;

    for (size_t i = 0; i < this->_wireframe.getRow(); i++)
    {
        for (size_t j = 0; j < this->_wireframe.getColumn(); j++)
        {
            /* Right Line */
            if (this->_wireframe[i][j] && this->_wireframe[i][j + 1])
            {
                Point p0(
                    x + this->_distance_x * j,
                    y + this->_distance_y * i
                );
                Point p1(
                    x + this->_distance_x * (j + 1),
                    y + this->_distance_y * i
                );
                
                this->drawLine(p0, p1);
            }

            /* Down Line */
            if (i + 1 < this->_wireframe.getRow() && this->_wireframe[i][j] && this->_wireframe[i + 1][j])
            {
                Point p0(
                    x + this->_distance_x * j,
                    y + this->_distance_y * i
                );
                Point p1(
                    x + this->_distance_x * j,
                    y + this->_distance_y * (i + 1)
                );
                
                this->drawLine(p0, p1);
            }

            /* Down-Right Line */
            if (i + 1 < this->_wireframe.getRow() && this->_wireframe[i][j] && this->_wireframe[i + 1][j + 1])
            {
                Point p0(
                    x + this->_distance_x * j,
                    y + this->_distance_y * i
                );
                Point p1(
                    x + this->_distance_x * (j + 1),
                    y + this->_distance_y * (i + 1)
                );
                
                this->drawLine(p0, p1);
            }

            /* Down-Left Line */
            if (i + 1 < this->_wireframe.getRow() && j != 0 &&
                this->_wireframe[i][j] && this->_wireframe[i + 1][j - 1])
            {
                Point p0(
                    x + this->_distance_x * j,
                    y + this->_distance_y * i
                );
                Point p1(
                    x + this->_distance_x * (j - 1),
                    y + this->_distance_y * (i + 1)
                );
                
                this->drawLine(p1, p0);
            }
        }
    }
}

// Implementation of Bresenham's line algorithm --------------------------------
void Engine::drawLine(Point p0, Point p1) const
{
    /* Set white pixels */
    SDL_SetRenderDrawColor(this->_render, 0xFF, 0xFF, 0xFF, 0xFF);

    int dx = p1.first - p0.first;
    int dy = p1.second - p0.second;
    if (!dx)
    {
        for (size_t y = p0.second; y < p1.second; ++y)
            SDL_RenderDrawPoint(this->_render, p0.first, y);   
    }
    else
    {
        double error = 0.0f;
        double derror = static_cast<double>(std::abs(dy)) / std::abs(dx);
        for(size_t x = p0.first, y = p0.second; x <= p1.first; ++x)
        {
            SDL_RenderDrawPoint(this->_render, x, y);
            error += derror;
            if(error > 0.5f)
            {
                y += static_cast<int>(std::abs(dy) / dy);
                error -= 1.0f;
            }
        }
    }
}

// Destructor of engine --------------------------------------------------------
Engine::~Engine()
{
    SDL_DestroyRenderer(this->_render);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}
