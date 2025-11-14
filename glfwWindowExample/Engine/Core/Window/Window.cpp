#include <iostream>
#include <string>
#include "Window.h"

namespace Engine 
{
    //Constructor
    Window::Window() :  glfwWindowControl(nullptr), width(0), height(0)
    {

    }

    //Deconstructor
    Window::~Window()
    {

    }

    //Functions
    bool Window::initWindow(int width, int height, const std::string& title)
    {   
        //start GLFW OpenGL Context
        if(!glfwInit())
        {
           std::cerr << "failed to initialize glfw >:(" << std::endl;
           return false;
        }
       
       //Creation of window
       glfwWindowControl = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
       
       if(!glfwWindowControl)
       {
            std::cerr << "Creation of window failed" << std::endl;
            glfwTerminate();
            return false;
       }

       //Set this window as the current session for OpenGL
       glfwMakeContextCurrent(glfwWindowControl);

       //Load GLAD OpenGL functions 
       if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
       {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            return false;
       }

       return true;
    }

    bool Window::windowShouldClose()
    {
        return glfwWindowShouldClose(glfwWindowControl);
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(glfwWindowControl);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();       //poll events = check for change in inputs
    }
}

