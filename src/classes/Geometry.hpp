#ifndef GEOMETRY_H
#define GEOMETRY_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h> 

#include <iostream>
#include <vector>

class Geometry{
    private:
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;

        std::vector<float> vertices;
        std::vector<unsigned int> indices;

    public:
        Geometry(std::vector<float>& vertices, std::vector<unsigned int>& indices);
        ~Geometry();

        void draw();
};

#endif