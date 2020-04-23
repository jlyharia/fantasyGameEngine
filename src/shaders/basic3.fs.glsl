#version 330 core
in vec2 pass_textureCoords;
out vec4 frag_colour;

uniform sampler2D textureSampler;
void main() {

//    frag_colour = vec4(colour, 1.0);
    frag_colour = texture(textureSampler, pass_textureCoords);
}