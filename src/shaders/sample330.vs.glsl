#version 330
layout (location = 0) in vec3 VertexPosition;
//layout (location = 1) in vec3 VertexNormal;
//in vec3 VertexPosition;
//out vec3 VertexInEye;
//out vec3 Normal;
//
//uniform mat4 ModelViewMatrix;
//uniform mat3 NormalMatrix;
//uniform mat4 MVP;

void main()
{
//    Normal = normalize( NormalMatrix * VertexNormal);
    //calculate correct normal in eye space
//    VertexInEye = vec3( ModelViewMatrix * vec4(VertexPosition,1.0) );
    //transform vertex from object space to eye space
    gl_Position = vec4(VertexPosition,1.0);
    //transform vertex from object space to perspective space
}
