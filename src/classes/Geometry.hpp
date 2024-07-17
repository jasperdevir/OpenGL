#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glad/glad.h> 
#include <glm/glm.hpp>

#include "texture.hpp"

#include <iostream>
#include <vector>

class Geometry{
    protected:
        unsigned int VAO;
        unsigned int VBO;

        std::vector<float> vertices;

        void init();

    public:
        Geometry();
        ~Geometry();

        void draw();

};

class BoxGeometry : public Geometry{
    private:

    public:
        BoxGeometry();
};

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Mesh{
    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        void init();
    
    public:
        Mesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices);

        void draw();
};

#endif