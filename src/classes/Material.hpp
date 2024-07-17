#ifndef MATERIAL_H
#define MATERIAL_H

#include "Shader.hpp"
#include "Camera.hpp"
#include "Texture.hpp"
#include "Light.hpp"

#include <string>
#include <vector>

class Material {
    protected:
        Shader* shader; 
        bool wireframe;

    public:
        Material();
        ~Material();

        Shader* getShader();
        void setWireframe(bool newWireframe);
        virtual void use(Camera* camera, glm::mat4 model);

};

class ShaderMaterial : public Material{
    private:

    public:
        ShaderMaterial(Shader* _shader);

        void setShader(Shader* newShader);
        void use(Camera* camera, glm::mat4 model) override;
};

class BasicMaterial : public Material{
    private:
        glm::vec4 color;

    public:
        BasicMaterial(glm::vec4 _color);

        void setColor(glm::vec4 newColor);
        void use(Camera* camera, glm::mat4 model) override;
};

class LightMaterial : public Material{
    private:

    public:
        LightMaterial();

        void bindLighting(AmbientLight* ambientLight, std::vector<Light*> lights);
};

class LambertMaterial : public LightMaterial{
    private:
        Texture* diffuseMap;
        glm::vec3 color;

    public:
        LambertMaterial(glm::vec3 _color);
        LambertMaterial(Texture* diffuseMap);
        ~LambertMaterial();

        void use(Camera* camera, glm::mat4 model) override;
};

class PhongMaterial : public LightMaterial{
    private:
        Texture* diffuseMap;
        Texture* specularMap;
        glm::vec3 color;
        float shininess;
        float specular;

    public:
        PhongMaterial(glm::vec3 _color, float _shininess, float _specular);
        PhongMaterial(Texture* diffuseMap, float _shinines, float _specular);
        PhongMaterial(Texture* diffuseMap, Texture* specularMap, float _shinines, float _specular);
        ~PhongMaterial();

        void use(Camera* camera, glm::mat4 model) override;
};

class TextureMaterial : public Material{
    private:
        Texture* diffuseTex;

    public:
        TextureMaterial(Texture* _diffuseTex);

        void use(Camera* camera, glm::mat4 model) override;
};

#endif