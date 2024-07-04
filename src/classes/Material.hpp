#ifndef MATERIAL_H
#define MATERIAL_H

#include "Shader.hpp"
#include "Camera.hpp"
#include "Texture.hpp"

#include <string>


class Material {
    protected:
        Shader* shader; 
        bool wireframe;

    public:
        Material();
        ~Material();

        Shader* getShader();
        void setWireframe(bool newWireframe);
        void use(Camera* camera, glm::mat4 model);

};

class ShaderMaterial : public Material{
    private:

    public:
        ShaderMaterial(Shader* _shader);

        void setShader(Shader* newShader);
};

class BasicMaterial : public Material{
    private:
        glm::vec4 color;

    public:
        BasicMaterial(glm::vec4 _color);

        void setColor(glm::vec4 newColor);
};

class LambertMaterial : public Material{
    private:

    public:
        LambertMaterial();
};

class PhongMaterial : public Material{
    private:

    public:
        PhongMaterial();
};

class TextureMaterial : public Material{
    private:
        Texture* diffuseTex;

    public:
        TextureMaterial(std::string diffusePath);
};

class LambertMaterialT : public TextureMaterial{
    private:

    public:
        LambertMaterialT(std::string diffusePath);
};

class PhongMaterialT : public TextureMaterial{
    private:

    public:
        PhongMaterialT(std::string diffusePath);
};

#endif