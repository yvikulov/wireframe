#pragma once

#include <stdexcept>

#include "SDL.h"

#include "Wireframe.hpp"

#define APPLICATION_NAME "Wireframe"

class Engine
{
private:
    // Const Window size -------------------------------------------------------
    const int _width = 800;
    const int _height = 800;

    Wireframe& _wireframe;

    // SDL objects -------------------------------------------------------------
    SDL_Window * _window;
    SDL_Renderer * _render;

public:
    // Default -----------------------------------------------------------------
    explicit Engine(Wireframe & wireframe);
    explicit Engine(const Engine & engine);
    Engine& operator=(const Engine & engine);
    ~Engine();

    // Start point -------------------------------------------------------------
    int run(void);
};
