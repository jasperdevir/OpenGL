#ifndef SCENE_H
#define SCENE_H

#include "Object.hpp"
#include "Camera.hpp"

#include <iostream>
#include <vector>

class Scene{

    private:
        std::vector<Object> children;
        Camera* camera;

        glm::vec4 background;
        
    public:
        Scene(Camera* camera);

        void add(Object object);
        Object getChild(int index);
        void setBackground(glm::vec4 newBackground);

        void render();
};

#endif