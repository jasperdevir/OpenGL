#include "Light.hpp"

Light::Light(glm::vec3 _color){
    color = _color;
}

void Light::bind(int index, Shader* shader){
    shader->use();
    std::string base = "lights[" + std::to_string(index) + "].";
    shader->setVec3(base + "color", color);
}

AmbientLight::AmbientLight(glm::vec3 _color, float _strength){
    color = _color;
    strength = _strength;
}

void AmbientLight::bind(Shader* shader){
    shader->use();
    shader->setVec3("ambientLight.color", color);
    shader->setFloat("ambientLight.strength", strength);
}

PointLight::PointLight(glm::vec3 _position, glm::vec3 _color, float _linear, float _quadratic)
: Light(_color) {
    position = _position;
    linear = _linear;
    quadratic = _quadratic;
    constant = 1.0f;
}

void PointLight::setConstant(float newConst){
    constant = newConst;
}

void PointLight::bind(int index, Shader* shader){
    Light::bind(index, shader);
    std::string base = "lights[" + std::to_string(index) + "].";
    shader->setInt(base + "type", POINT_LIGHT);
    shader->setVec3(base + "position", position);
    shader->setFloat(base + "constant", constant);
    shader->setFloat(base + "linear", linear);
    shader->setFloat(base + "quadratic", quadratic);
}

DirectionalLight::DirectionalLight(glm::vec3 _color, glm::vec3 _direction)
: Light(_color) {
    direction = _direction;
}

void DirectionalLight::bind(int index, Shader* shader){
    Light::bind(index, shader);
    std::string base = "lights[" + std::to_string(index) + "].";
    shader->setInt(base + "type", DIRECTIONAL_LIGHT);
    shader->setVec3(base + "direction", direction);
}

SpotLight::SpotLight(glm::vec3 _position, glm::vec3 _color, glm::vec3 _direction, float _cutOff, float _outerCutOff, float _linear, float _quadratic)
: Light(_color) {
    position = _position;
    direction = _direction;
    cutOff = _cutOff;
    outerCutOff = _outerCutOff;
    constant = 1.0f;
    linear = _linear;
    quadratic = _quadratic;
}

void SpotLight::bind(int index, Shader* shader){
    Light::bind(index, shader);
    std::string base = "lights[" + std::to_string(index) + "].";
    shader->setInt(base + "type", SPOT_LIGHT);
    shader->setVec3(base + "position", position);
    shader->setVec3(base + "direction", direction);
    shader->setFloat(base + "cutOff", cutOff);
    shader->setFloat(base + "outerCutOff", outerCutOff);
    shader->setFloat(base + "constant", constant);
    shader->setFloat(base + "linear", linear);
    shader->setFloat(base + "quadratic", quadratic);
}