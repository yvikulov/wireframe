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
            this->_grid.push_back(std::vector<bool>());
            for (size_t j = 0; j < this->_column; j++)
            {
                WireframeFile >> point;
                this->_grid[i].push_back(point);
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
        this->_path = new char[strlen(wireframe.getPath()) + 1];
        strcpy(this->_path, wireframe.getPath());

        std::ifstream WireframeFile(this->_path);

        if (WireframeFile.is_open())
        {
            bool point;

            WireframeFile >> this->_row >> this->_column;
            for (size_t i = 0; i < this->_row; i++)
            {
                this->_grid.push_back(std::vector<bool>());
                for (size_t j = 0; j < this->_column; j++)
                {
                    WireframeFile >> point;
                    this->_grid[i].push_back(point);
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
}

// Copy constructor ------------------------------------------------------------
Wireframe& Wireframe::operator=(const Wireframe & wireframe)
{
    if (&wireframe != this)
    {
        this->_path = new char[strlen(wireframe.getPath()) + 1];
        strcpy(this->_path, wireframe.getPath());

        std::ifstream WireframeFile(this->_path);

        if (WireframeFile.is_open())
        {
            bool point;

            WireframeFile >> this->_row >> this->_column;
            for (size_t i = 0; i < this->_row; i++)
            {
                this->_grid.push_back(std::vector<bool>());
                for (size_t j = 0; j < this->_column; j++)
                {
                    WireframeFile >> point;
                    this->_grid[i].push_back(point);
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
    return *this;
}

// Get point from vector -------------------------------------------------------
std::vector<bool> Wireframe::operator[](int i)
{
    this->_i = i;
    std::vector<bool> v = this->_grid[i];
    return v;
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
    size_t size = 0;

    for (size_t i = 0; i < this->getRow(); i++)
        size += this->_grid.size();
    
    return size;
}

Wireframe::~Wireframe()
{
    if (this->_path)
        delete[] this->_path;
}
