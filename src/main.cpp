#include <GLFW/glfw3.h>
#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "classes/Geometry.hpp"
#include "classes/Shader.hpp"
#include "classes/Light.hpp"
#include "classes/Material.hpp"
#include "classes/Window.hpp"
#include "classes/Clock.hpp"
#include "classes/Camera.hpp"
#include "classes/Object.hpp"
#include "classes/Scene.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    Window window = Window(SCR_WIDTH, SCR_HEIGHT, "Window");
    
    if(!window.init()){
        return -1;
    }
    Camera camera = Camera(glm::vec2(SCR_WIDTH, SCR_HEIGHT), 0.01f, 100.0f);
    camera.setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
    Scene scene = Scene(&camera);
    scene.setBackground(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    Clock clock = Clock();

    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f), 
        glm::vec3( 2.0f,  5.0f, -15.0f), 
        glm::vec3(-1.5f, -2.2f, -2.5f),  
        glm::vec3(-3.8f, -2.0f, -12.3f),  
        glm::vec3( 2.4f, -0.4f, -3.5f),  
        glm::vec3(-1.7f,  3.0f, -7.5f),  
        glm::vec3( 1.3f, -2.0f, -2.5f),  
        glm::vec3( 1.5f,  2.0f, -2.5f), 
        glm::vec3( 1.5f,  0.2f, -1.5f), 
        glm::vec3(-1.3f,  1.0f, -1.5f)  
    };

    BoxGeometry geometry = BoxGeometry();

    Texture diffuse = Texture("../assets/textures/container.jpg");
    PhongMaterial material = PhongMaterial(&diffuse, 32.0f, 0.5f);
    material.setWireframe(false);

    glm::vec3 pointLightPositions[] = {
        glm::vec3( 0.7f,  0.2f,  2.0f),
        glm::vec3( 2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3( 0.0f,  0.0f, -3.0f)
    };  

    AmbientLight* ambientLight = new AmbientLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.1f);
    for(int i = 0; i < 4; i++){
        PointLight* light = new PointLight(pointLightPositions[i], glm::vec3(1.0f, 1.0f, 1.0f), 0.09f, 0.032f);
        scene.add(light);
    }
    scene.add(ambientLight);

    for(int i = 0; i < 10; i++){
        Object object(&geometry, &material);
        object.setPosition(cubePositions[i]);
        float angle = 30.0f * i;
        object.setRotation(angle, glm::vec3(1.0f, 0.3f, 0.5f));
        scene.add(object);
    }

    scene.bindLighting();

    const float radius = 10.0f;

    while (!window.shouldWindowClose())
    {
        clock.tick();

        /* INPUT */
        window.processInput();

        /* RENDER */
        float camX = sin(clock.getElapsedTime()) * radius;
        float camZ = cos(clock.getElapsedTime()) * radius;

        camera.setPosition(glm::vec3(camX, 0.0f, camZ));
        camera.lookAt(glm::vec3(0.0f));
        scene.render();

        window.swapBuffer();
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

