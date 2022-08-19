#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Wireframe
{
private:
    // The path to the file that contains the wireframe ------------------------
    char * _path = nullptr;

    // Size of wireframe grid --------------------------------------------------
    unsigned int _row = 0;
    unsigned int _column = 0;

    // Grid --------------------------------------------------------------------
    std::vector<std::vector<bool>> _grid;
    size_t _i = 0;

public:
    // Default -----------------------------------------------------------------
    // explicit Wireframe(const char * path, bool COORD); RELATIVE, ABSOLUTE
    explicit Wireframe(const char * path);
    explicit Wireframe(const Wireframe & wireframe);
    Wireframe& operator=(const Wireframe & wireframe);
    ~Wireframe();

    // Get point ---------------------------------------------------------------
    std::vector<bool> operator[](int i);

    // Size of array -----------------------------------------------------------
    size_t size(void) const;

    // Gets --------------------------------------------------------------------
    const char * getPath(void) const;
    unsigned int getRow(void) const;
    unsigned int getColumn(void) const;
};
