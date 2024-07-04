#include "Scene.hpp"

Scene::Scene(Camera* _camera){
    camera = _camera;
};

void Scene::add(Object object){
    children.push_back(object);
};

Object Scene::getChild(int index){
    return children.at(index);
};

void Scene::setBackground(glm::vec4 newBackground){
    background = newBackground;
}

void Scene::render(){
    glClearColor(background.r, background.g, background.b, background.a);
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(Object o : children){
        o.render(camera);
    }
}