#include "Shader.hpp"

Shader::Shader() {}

Shader::Shader(std::string vertPath, std::string fragPath) {
    std::string vertShaderSrc = parseShader(vertPath).c_str();
    std::string fragShaderSrc = parseShader(fragPath).c_str();

    unsigned int vertexShader = initShader(vertShaderSrc, 0);
    unsigned int fragmentShader = initShader(fragShaderSrc, 1);

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

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

std::string Shader::parseShader(std::string path){
    std::string shaderCode = "";
    std::ifstream shaderFile;

    try {
        shaderFile.open(path);

        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();	
        	
        shaderFile.close();

        shaderCode = shaderStream.str();	
    }
    catch(std::ifstream::failure e){
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    return shaderCode;
}

unsigned int Shader::initShader(std::string shaderSrc, int type){
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

    const char* src = shaderSrc.c_str();

    glShaderSource(shader, 1, &src, NULL);
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
    glDeleteProgram(shaderProgram);
}

void Shader::setBool(const std::string &name, bool value){         
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value){ 
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value){ 
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value); 
} 

void Shader::setVec3(const std::string &name, glm::vec3 value){ 
    glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), value.x, value.y, value.z); 
} 

void Shader::setVec4(const std::string &name, glm::vec4 value){ 
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), value.x, value.y, value.z, value.w); 
} 

void Shader::setMat4(const std::string &name, glm::mat4 value){
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));   
}