#ifndef SHADER_H
#define SHADER_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h> 

#include <iostream>

class Shader{
    private:
        unsigned int vertexShader;
        unsigned int fragmentShader;
        unsigned int shaderProgram;

        unsigned int initShader(const char* shaderSrc, int type);

    public:
        Shader(const char* vertShaderSrc, const char* fragShaderSrc);
        ~Shader();

        void use();

};

#endif