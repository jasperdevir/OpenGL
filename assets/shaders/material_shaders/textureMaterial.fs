#version 330 core

in vec2 TexCoord;

uniform sampler2D diffuseTex;

out vec4 FragColor;

void main(){
    FragColor = texture(diffuseTex, TexCoord);
}