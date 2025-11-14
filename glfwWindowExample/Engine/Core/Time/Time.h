#pragma once
#include <chrono>

namespace Engine
{
    class Time
    {
        public:
        //Constructor
            Time();
        //Deconstructor
            ~Time();
        //Functions
            void init();
            void update();
            double getDeltaTime() const;
            double getElapsedTime() const;
        private:
            std::chrono::high_resolution_clock::time_point startTime;
            std::chrono::high_resolution_clock::time_point lastFrame;
            double deltaTime; // seconds between frames
    };
}
