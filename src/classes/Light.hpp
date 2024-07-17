#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>

#include "Shader.hpp"

class Light{
    private:
        glm::vec3 color;

    public:
        Light(glm::vec3 color);

        virtual void bind(int index, Shader* shader);
};

class AmbientLight{
    private:
        glm::vec3 color;
        float strength;

    public:
        AmbientLight(glm::vec3 color, float strength);

        void bind(Shader* shader);
};

enum LightType {
    POINT_LIGHT,
    DIRECTIONAL_LIGHT,
    SPOT_LIGHT
};

class PointLight : public Light{
    private:
        glm::vec3 position;
        float constant;
        float linear;
        float quadratic;
    
    public:
        PointLight(glm::vec3 position, glm::vec3 color, float linear, float quadratic);

        void bind(int index, Shader* shader) override;
        void setConstant(float newConst);
};

class DirectionalLight : public Light{
    private:
        glm::vec3 direction;

    public:
        DirectionalLight(glm::vec3 color, glm::vec3 direction);

        void bind(int index, Shader* shader) override;
};

class SpotLight : public Light{
    private:
        glm::vec3 position;
        glm::vec3 direction;
        float cutOff;
        float outerCutOff;
        float linear;
        float quadratic;
        float constant;

    public:
        SpotLight(glm::vec3 position, glm::vec3 color, glm::vec3 direction, float cutOff, float outerCutOff, float linear, float quadratic);

        void bind(int index, Shader* shader) override;
};

#endif