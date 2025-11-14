#pragma once
#include <string>
#include "Time/Time.h"
#include "Window/Window.h"

namespace Engine
{
    class Application
    {
        public:
        //place the settings and parameters of each system for the engine, this is where the settings for the options menu will be held!!!

        //Constructor
            Application();
        //Deconstructor 
            ~Application();

        //Functions
            bool initApplication();
            void runApplication();
        
        //Settings

        //Window Settings
            int windowWidth = 1280;
            int windowHeight = 720;
            std::string windowTitle = "Liminality";

        private:
        //place preallocated objects here

        //Window display control object
            Window window;
        //Time sync control object
            Time timeControl;
    };
}