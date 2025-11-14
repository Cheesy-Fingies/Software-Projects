#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Engine
{
    class Window
    {
        public:
        //Constructor
            Window();
        //Deconstructor
            ~Window();
        //Functions
            bool initWindow(int width, int height, const std::string& title);
            bool windowShouldClose();
            void swapBuffers();
            void pollEvents();
        private:
        //GLFW Control Object
            GLFWwindow* glfwWindowControl;
        //Private properties
            int width;
            int height;
            std::string title;
    };
}