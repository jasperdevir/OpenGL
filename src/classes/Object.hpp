#ifndef OBJECT_H
#define OBJECT_H

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 

#include "Geometry.hpp"
#include "Material.hpp"
#include "Camera.hpp"

class Object{
    private:
        Geometry* geometry;
        Material* material;
        glm::vec3 position;
        glm::vec3 scale;
        glm::mat4 rotation;
        glm::mat4 model;

    public:

        Object(Geometry* _geometry, Material* _material);

        void setPosition(glm::vec3 newPosition);
        void setScale(glm::vec3 newScale);
        void setRotation(float newRotation, glm::vec3 axis);
        void updateModel();

        void render(Camera* camera);
};  

#endif