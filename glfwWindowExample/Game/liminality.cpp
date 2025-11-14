#include <iostream>
#include <string>
#include "Core/Application/Application.h"

int main ()
{
    //Create app object
    Engine::Application liminality;

    //ensure clean launch
    if(!liminality.initApplication())
    {
        std::cerr << "Failed to initialize the application: liminality";
        return -1;
    }

    //Finally, run the engine
    liminality.runApplication();

    return 0;
}