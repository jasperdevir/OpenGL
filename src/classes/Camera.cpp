#include "Camera.hpp"

Camera::Camera(){}

Camera::Camera(glm::vec2 resolution, float near, float far){
    projection = glm::perspective(glm::radians(45.0f), (float)resolution.x / (float)resolution.y, near, far);
    view = glm::mat4(1.0f);
    position = glm::vec3(0.0f);
};

void Camera::setPosition(glm::vec3 newPosition){
    position = newPosition;
    view = glm::translate(view, newPosition);
}

void Camera::lookAt(glm::vec3 target){
    view = glm::lookAt(
        position,
        target,
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
}

glm::vec3 Camera::getPosition(){
    return position;
}

glm::mat4 Camera::getProjection(){
    return projection;
}

glm::mat4 Camera::getView(){
    return view;
}