#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>

class Window {
    private:
        GLFWwindow* glfwWindow;
        int windowWidth;
        int windowHeight;
        const char* windowTitle;

        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

    public:
        Window(int width, int height, const char* title);
        ~Window();
        
        bool init();

        bool shouldWindowClose();
        void processInput();
        void swapBuffer();

};

#endif