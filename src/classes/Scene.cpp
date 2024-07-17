#include "Scene.hpp"

Scene::Scene(Camera* _camera){
    glEnable(GL_DEPTH_TEST);
    camera = _camera;
};

Scene::~Scene(){
    delete ambientLight;
    for(Light* l : lights){
        delete l;
    }
}

void Scene::add(Object object){
    children.push_back(object);
};

void Scene::add(AmbientLight* _ambientLight){
    ambientLight = _ambientLight;
};

void Scene::add(Light* _light){
    lights.push_back(_light);
};

void Scene::bindLighting(){
    for(Object o : children){
        o.bindLighting(ambientLight, lights);
    }
}

Object Scene::getChild(int index){
    return children.at(index);
};

void Scene::setBackground(glm::vec4 newBackground){
    background = newBackground;
}

void Scene::render(){
    glClearColor(background.r, background.g, background.b, background.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for(Object o : children){
        o.render(camera);
    }
}