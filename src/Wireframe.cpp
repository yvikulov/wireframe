#include "Wireframe.hpp"

// Default constructor ---------------------------------------------------------
Wireframe::Wireframe(const char * path)
{
    this->_path = new char[strlen(path) + 1];
    strcpy(this->_path, path);

    std::ifstream WireframeFile(this->_path);

    if (WireframeFile.is_open())
    {
        bool point;

        WireframeFile >> this->_row >> this->_column;
        for (size_t i = 0; i < this->_row; i++)
        {
            for (size_t j = 0; j < this->_column; j++)
            {
                WireframeFile >> point;
                if (point)
                    this->_vpos.push_back(Point(i, j));
            }
        }
    }
    else
    {
        delete[] this->_path;
        this->_path = nullptr;
    }
    
    WireframeFile.close();
}

// Copy constructor ------------------------------------------------------------
Wireframe::Wireframe(const Wireframe & wireframe)
{
    if (&wireframe != this)
    {
        std::ifstream WireframeFile(wireframe.getPath());

        if (WireframeFile.is_open())
        {
            bool point;

            WireframeFile >> this->_row >> this->_column;
            for (size_t i = 0; i < this->_row; i++)
            {
                for (size_t j = 0; j < this->_column; j++)
                {
                    WireframeFile >> point;
                    if (point)
                        this->_vpos.push_back(Point(i, j));
                }
            }
        }
    }
}

// Copy constructor ------------------------------------------------------------
Wireframe& Wireframe::operator=(const Wireframe & wireframe)
{
    if (&wireframe != this)
    {
        std::ifstream WireframeFile(wireframe.getPath());

        if (WireframeFile.is_open())
        {
            bool point;

            WireframeFile >> this->_row >> this->_column;
            for (size_t i = 0; i < this->_row; i++)
            {
                for (size_t j = 0; j < this->_column; j++)
                {
                    WireframeFile >> point;
                    if (point)
                        this->_vpos.push_back(Point(i, j));
                }
            }
        }
    }
    return *this;
}

// Get point from vector -------------------------------------------------------
Wireframe::Point Wireframe::operator[](size_t i) const
{
    if (i < this->size())
        return this->_vpos[i];
    return Wireframe::Point(-1, -1);
}

// Gets ------------------------------------------------------------------------
const char * Wireframe::getPath(void) const
{
    return this->_path;
}

unsigned int Wireframe::getRow(void) const
{
    return this->_row;
}

unsigned int Wireframe::getColumn(void) const
{
    return this->_column;
}

// Size of vector of points ----------------------------------------------------
size_t Wireframe::size(void) const
{
    return this->_vpos.size();
}

Wireframe::~Wireframe()
{
    if (this->_path)
        delete[] this->_path;
}
