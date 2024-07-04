#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glad/glad.h> 

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

#endif