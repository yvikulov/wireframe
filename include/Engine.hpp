#pragma once

#include <cstdlib>
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

    // Start location of the first point ---------------------------------------
    size_t _start_x = 100;
    size_t _start_y = 100;

    // Distance between two points ---------------------------------------------
    size_t _distance_x = 50;
    size_t _distance_y = 50;

    // Wireframe grid with points ----------------------------------------------
    Wireframe& _wireframe;

    // Type of the points ------------------------------------------------------
    using Point = std::pair<int, int>;

    // SDL objects -------------------------------------------------------------
    SDL_Window * _window;
    SDL_Renderer * _render;

    // Render the wireframe grid -----------------------------------------------
    void renderWireframe(void);

    // Bresenham's line algorithm ----------------------------------------------
    void drawLine(Point p0, Point p1) const;

public:
    // Default -----------------------------------------------------------------
    explicit Engine(Wireframe & wireframe);
    ~Engine();

    // Start point -------------------------------------------------------------
    int run(void);
};
