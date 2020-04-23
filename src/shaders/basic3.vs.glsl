#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoords;

out vec2 pass_textureCoords;

void main(){
    gl_Position = vec4(position, 1.0);
//    colour = vec3(position.x+0.5, 0.0, position.y+0.5);
    pass_textureCoords = vec2(textureCoords.x, textureCoords.y);
}
