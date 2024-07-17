#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

#include <string>
#include <iostream>

class Texture{
    private:
        unsigned int texture;

    public:
        Texture(std::string path);

        void bind(int index);
        unsigned int getTexture();

};

#endif

