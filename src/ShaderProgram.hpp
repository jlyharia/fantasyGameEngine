//
// Created by Yihung Lee on 4/12/20.
//

#ifndef FANTASYGAMEENGINE_SHADERPROGRAM_HPP
#define FANTASYGAMEENGINE_SHADERPROGRAM_HPP

#include <GL/glew.h>
#include <string>
#include <iostream>

class ShaderProgram {
public:
    ShaderProgram(std::string vertexFile, std::string fragmentFile);

    void start();

    void stop();

    virtual ~ShaderProgram();

protected:
    virtual void bindAttributes() {};

    void bindAttribute(int attribute, std::string variableName);

private:
    int programId;
    int vertexShaderId;
    int fragmentShaderId;


    GLuint createShaders(std::string filename, int shaderType);

    char *readFile(char *fn);

    void printShaderInfoLog(GLuint obj);

    void printProgramInfoLog(GLuint obj);

};


#endif //FANTASYGAMEENGINE_SHADERPROGRAM_HPP
