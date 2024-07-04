#include "Object.hpp"

Object::Object(Geometry* _geometry, Material* _material){
    geometry = _geometry;
    material = _material;
    position = glm::vec3(0.0f); 
    rotation = glm::mat4(1.0f);  
    scale = glm::vec3(1.0f);  
    model = glm::mat4(1.0f); 
};
void Object::setPosition(glm::vec3 newPosition){
    position = newPosition;
}

void Object::setRotation(float degrees, glm::vec3 axis){
    glm::mat4 newRotation = glm::mat4(1.0f);
    newRotation = glm::rotate(newRotation, glm::radians(degrees), axis);
    rotation = newRotation;
}

void Object::setScale(glm::vec3 newScale){
    scale = newScale;
}

void Object::updateModel(){
    model = glm::translate(glm::mat4(1.0f), position) * rotation * glm::scale(glm::mat4(1.0f), scale);
}

void Object::render(Camera* camera){
    updateModel();
    material->use(camera, model);
    geometry->draw();
}