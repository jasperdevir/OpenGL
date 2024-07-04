#ifndef CLOCK_H
#define CLOCK_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Clock{
    private:
        float elapsedTime;
        float previousTick;

    public:

        Clock();

        void tick();

        float getElapsedTime();
        float getDelta();
};

#endif