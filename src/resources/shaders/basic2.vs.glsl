#version 330
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;

out vec3 VertexInEye;
out vec3 Normal;

uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 MVP;

void main()
{
    //calculate correct normal in eye space
//    Normal = normalize( NormalMatrix * VertexNormal);

    //transform vertex from object space to eye space
//	VertexInEye = vec3( ModelViewMatrix * vec4(VertexPosition,1.0) );

    //transform vertex from object space to perspective space
//	gl_Position = MVP * vec4(VertexPosition,1.0);
    gl_Position = vec4(VertexPosition,1.0);
}
