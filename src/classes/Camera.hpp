#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
    private:
        glm::mat4 projection;
        glm::mat4 view;

        glm::vec3 position;

    public:
        Camera();
        Camera(glm::vec2 resolution, float near, float far);

        void setPosition(glm::vec3 position);
        void lookAt(glm::vec3 target);

        glm::mat4 getProjection();
        glm::mat4 getView();
};

#endif