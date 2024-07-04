#include "Clock.hpp"

Clock::Clock(){
    elapsedTime = 0.0f;
    previousTick = 0.0f;
}

void Clock::tick(){
    previousTick = elapsedTime;
    elapsedTime = glfwGetTime();
}

float Clock::getElapsedTime(){
    return elapsedTime;
}

float Clock::getDelta(){
    return glfwGetTime() - previousTick;
}