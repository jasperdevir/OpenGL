#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
    private:
        unsigned int shaderProgram;

        std::string parseShader(std::string path);
        unsigned int initShader(std::string shaderSrc, int type);

    public:
        Shader();
        Shader(std::string vertPath, std::string fragPath);
        ~Shader();

        void use();

        void setBool(const std::string &name, bool value);
        void setInt(const std::string &name, int value);   
        void setFloat(const std::string &name, float value);
        void setVec3(const std::string &name, glm::vec3 value);
        void setVec4(const std::string &name, glm::vec4 value);
        void setMat4(const std::string &name, glm::mat4 value);

};

#endif