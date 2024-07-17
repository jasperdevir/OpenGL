#version 330 core

struct Material {
    bool hasDiffuseMap;
    vec3 color;
    sampler2D diffuseMap;
};

struct AmbientLight {
    vec3 color;
    float strength;
};

struct Light {
    int type;
    vec3 position;
    vec3 direction;
    vec3 color;

    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;
};

in vec3 Normal;
in vec3 FragPos; 
in vec3 ViewPos;
in vec2 TexCoord;

#define MAX_LIGHTS 16

uniform Material material;
uniform AmbientLight ambientLight;
uniform Light lights[MAX_LIGHTS];
uniform int numLights;

out vec4 FragColor;

vec3 calcLighting(int index, vec3 ambient){
    vec3 norm = normalize(Normal);
    vec3 lightDir;
    if(lights[index].type == 0 || lights[index].type == 2){
        lightDir = normalize(lights[index].position - FragPos);
    } else if (lights[index].type == 1) {
        lightDir = normalize(-lights[index].direction);
    }
    
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = vec3(0.0f);
    if(material.hasDiffuseMap){
        diffuse = diff * texture(material.diffuseMap, TexCoord).rgb * lights[index].color;
    } else {
        diffuse = (diff * material.color) * lights[index].color;
    }
    

    if(lights[index].type == 2){
        float theta = dot(lightDir, normalize(-lights[index].direction)); 
        float epsilon = (lights[index].cutOff - lights[index].outerCutOff);
        float intensity = clamp((theta - lights[index].outerCutOff) / epsilon, 0.0, 1.0);
        diffuse  *= intensity;
    }
    
    if(lights[index].type == 0 || lights[index].type == 2){
        float distance    = length(lights[index].position - FragPos);
        float attenuation = 1.0 / (lights[index].constant + lights[index].linear * distance + lights[index].quadratic * (distance * distance));  

        ambient *= attenuation; 
        diffuse *= attenuation;
    }

    return ambient + diffuse;
}

void main(){
    vec3 ambient = vec3(0.0f);
    if(material.hasDiffuseMap){
        ambient = texture(material.diffuseMap, TexCoord).rgb * (ambientLight.color * ambientLight.strength);
    } else {
        ambient = material.color * ambientLight.color * ambientLight.strength;
    }
    
  	
    vec3 output = vec3(0.0f);

    for(int i = 0; i < numLights; i++){
        output += calcLighting(i, ambient);
    }    
    
    FragColor = vec4(output, 1.0f);
}