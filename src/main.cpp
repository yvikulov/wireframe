#include "Engine.hpp"

int main(void)
{
    const char * path = "./assets/wireframe.txt";
    Wireframe wireframe(path);
    
    return Engine(wireframe).run();
}
