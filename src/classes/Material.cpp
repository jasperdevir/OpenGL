#include "Material.hpp"

Material::Material(){
    shader = nullptr;
    wireframe = false;
}

Material::~Material(){
    delete shader;
}

Shader* Material::getShader(){
    return shader;
}

void Material::setWireframe(bool newWirefame){
    wireframe = newWirefame;
}

void Material::use(Camera* camera, glm::mat4 model){
    if(wireframe){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    if(shader){
        shader->use();
        shader->setMat4("projection", camera->getProjection()); 
        shader->setMat4("view", camera->getView());
        shader->setMat4("model", model);
    }
}

ShaderMaterial::ShaderMaterial(Shader* _shader){
    shader = _shader;
}

void ShaderMaterial::setShader(Shader* newShader){
    shader = newShader;
}

const std::string path = "../assets/shaders/material_shaders/";

BasicMaterial::BasicMaterial(glm::vec4 _color){
    color = _color;
    shader = new Shader(path + "base.vs", path + "basicMaterial.fs");
    shader->use();
    shader->setVec4("color", color);
}

void BasicMaterial::setColor(glm::vec4 newColor){
    color = newColor;
    shader->use();
    shader->setVec4("color", color);
}

LambertMaterial::LambertMaterial(){

}

PhongMaterial::PhongMaterial(){

}

TextureMaterial::TextureMaterial(std::string diffusePath){

}

LambertMaterialT::LambertMaterialT(std::string diffusePath) : TextureMaterial(diffusePath) {

}

PhongMaterialT::PhongMaterialT(std::string diffusePath) : TextureMaterial(diffusePath) {

}