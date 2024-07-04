#ifndef TEXTURE_H
#define TEXTURE_H

#include "../include/stb_image/stb_image.h"

#include <glad/glad.h>

#include <string>
#include <iostream>

class Texture{
    private:
        unsigned int texture;

    public:
        Texture(std::string path);

        void bind();

};

#endif

