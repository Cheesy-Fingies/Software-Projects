#include <iostream>
#include "Application.h"

namespace Engine
{
    //Constructor
        Application::Application()
        {
            
        }
    //Destructor
        Application::~Application()
        {

        }   

    //Functions
        bool Application::initApplication()
        {
            timeControl.init();

            if(!window.initWindow(windowWidth, windowHeight, windowTitle))
            {
                std::cerr << "GLFW Window could not initialize" << std::endl;
                return false;
            }   

            return true;
        }

        void Application::runApplication()  //Main Application loop (pseudo main)
        {
            while(!window.windowShouldClose())
            {
                //Check for Inputs

                    //input functions......

                //Move frame forward and Render
                timeControl.update();

                std::cout << "FPS: " << (1.0 / (timeControl.getDeltaTime())) << std:: endl; 

                //Check and call events
                window.swapBuffers();    //swap buffers framebuffers front to back
                window.pollEvents();       //poll events = inputs
            }

        }
}