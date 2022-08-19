#include "Engine.hpp"

int main(void)
{
    const char * path = "./assets/wireframe.txt";
    Wireframe wireframe(path);

    for (size_t i = 0; i < wireframe.getRow(); i++)
    {
        for (size_t j = 0; j < wireframe.getColumn(); j++)
        {
            std::cout << wireframe[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return Engine(wireframe).run();
}
