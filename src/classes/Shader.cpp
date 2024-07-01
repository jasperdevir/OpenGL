#include "Shader.hpp"

Shader::Shader(const char* vertShaderSrc, const char* fragShaderSrc)
{
    vertexShader = initShader(vertShaderSrc, 0);
    fragmentShader = initShader(fragShaderSrc, 1);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

unsigned int Shader::initShader(const char* shaderSrc, int type){
    unsigned int shader;
    switch (type){
        case 0:
            shader = glCreateShader(GL_VERTEX_SHADER);
            break;

        case 1:
            shader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
            
        default:
            std::cerr << "ERROR::SHADER::Invalid shader type\n";
            return 0;
    }

    glShaderSource(shader, 1, &shaderSrc, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success){
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

void Shader::use(){
    glUseProgram(shaderProgram);
}

Shader::~Shader(){
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(shaderProgram);
}