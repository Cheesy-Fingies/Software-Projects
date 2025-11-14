#include <chrono>
#include "Time.h"

namespace Engine
{
    //Constructor
    Time::Time() : deltaTime(0.0)
    {

    }

    //Destructor
    Time::~Time()
    {

    }

    //Functions
    void Time::init()
    {
        startTime = std::chrono::high_resolution_clock::now();
        lastFrame = startTime;
    }

    void Time::update()
    {
        auto now = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<double>(now - lastFrame).count();
        lastFrame = now;
    }

    double Time::getDeltaTime() const
    {
        return deltaTime;
    }

    double Time::getElapsedTime() const
    {   
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(now - startTime).count();
    }

}
