#ifndef SCENE_H
#define SCENE_H

#include "Object.hpp"
#include "Camera.hpp"
#include "Light.hpp"

#include <iostream>
#include <vector>

class Scene{

    private:
        std::vector<Object> children;
        AmbientLight* ambientLight;
        std::vector<Light*> lights;
        Camera* camera;

        glm::vec4 background;
        
    public:
        Scene(Camera* camera);
        ~Scene();

        void add(Object object);
        void add(AmbientLight* light);
        void add(Light* light);
        void bindLighting();
        Object getChild(int index);
        void setBackground(glm::vec4 newBackground);

        void render();
};

#endif