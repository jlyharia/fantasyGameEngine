#version 400 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 VertexNormal;

out vec3 VertexInEye;
out vec3 Normal;
out vec3 colour;
uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 MVP;

void main(){
    gl_Position = vec4(position, 1.0);
    colour = vec3(position.x+0.5, 0.0, position.y+0.5);
}
