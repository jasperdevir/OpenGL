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
        shader->setVec3("viewPos", camera->getPosition());
        shader->setMat4("projection", camera->getProjection()); 
        shader->setMat4("view", camera->getView());
        shader->setMat4("model", model);
    }
}

ShaderMaterial::ShaderMaterial(Shader* _shader){
    shader = _shader;
}

void ShaderMaterial::use(Camera* camera, glm::mat4 model){
    Material::use(camera, model);
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

void BasicMaterial::use(Camera* camera, glm::mat4 model){
    Material::use(camera, model);
}

LightMaterial::LightMaterial(){}

void LightMaterial::bindLighting(AmbientLight* ambientLight, std::vector<Light*> lights){
    shader->setInt("numLights", lights.size());
    ambientLight->bind(shader);
    for(int i = 0; i < lights.size(); i++){
        lights[i]->bind(i, shader);
    }
}

LambertMaterial::LambertMaterial(glm::vec3 _color){
    color = _color;
    shader = new Shader(path + "lambertMaterial.vs", path + "lambertMaterial.fs");
    shader->use();
    shader->setVec3("material.color", color);
}

LambertMaterial::LambertMaterial(Texture* _diffuseMap){
    diffuseMap = _diffuseMap;
    shader = new Shader(path + "lambertMaterial.vs", path + "lambertMaterial.fs");
    shader->use();
    shader->setInt("material.diffuseMap", 0);
    shader->setBool("material.hasDiffuseMap", true);
    diffuseMap->bind(0);
}

LambertMaterial::~LambertMaterial(){
    delete diffuseMap;
}

void LambertMaterial::use(Camera* camera, glm::mat4 model){
    Material::use(camera, model);
}

PhongMaterial::PhongMaterial(glm::vec3 _color, float _shininess, float _specular){
    color = _color;
    shininess = _shininess;
    specular = _specular;
    shader = new Shader(path + "phongMaterial.vs", path + "phongMaterial.fs");
    shader->use();
    shader->setVec3("material.color", color);
    shader->setFloat("material.shininess", shininess);
    shader->setFloat("material.specular", specular);
}

PhongMaterial::PhongMaterial(Texture* _diffuseMap, float _shininess, float _specular){
    diffuseMap = _diffuseMap;
    shininess = _shininess;
    specular = _specular;
    shader = new Shader(path + "phongMaterial.vs", path + "phongMaterial.fs");
    shader->use();
    shader->setInt("material.diffuseMap", 0);
    shader->setBool("material.hasDiffuseMap", true);
    diffuseMap->bind(0);
    shader->setFloat("material.shininess", shininess);
    shader->setFloat("material.specular", specular);
}

PhongMaterial::PhongMaterial(Texture* _diffuseMap, Texture* _specularMap, float _shininess, float _specular){
    diffuseMap = _diffuseMap;
    specularMap = _specularMap;
    shininess = _shininess;
    specular = _specular;
    shader = new Shader(path + "phongMaterial.vs", path + "phongMaterial.fs");
    shader->use();
    shader->setInt("material.diffuseMap", 0);
    shader->setBool("material.hasDiffuseMap", true);
    diffuseMap->bind(0);
    shader->setInt("material.specularMap", 1);
    shader->setBool("material.hasSpecularMap", true);
    specularMap->bind(1);
    shader->setFloat("material.shininess", shininess);
    shader->setFloat("material.specular", specular);
}

PhongMaterial::~PhongMaterial(){
    delete diffuseMap;
    delete specularMap;
}

void PhongMaterial::use(Camera* camera, glm::mat4 model){
    Material::use(camera, model);
}

TextureMaterial::TextureMaterial(Texture* _diffuseTex){
    diffuseTex = _diffuseTex;
    shader = new Shader(path + "base.vs", path + "textureMaterial.fs");
}

void TextureMaterial::use(Camera* camera, glm::mat4 model){
    diffuseTex->bind(0);
    Material::use(camera, model);
}