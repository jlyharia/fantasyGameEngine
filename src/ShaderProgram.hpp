//
// Created by Yihung Lee on 4/12/20.
//

#ifndef FANTASYGAMEENGINE_SHADERPROGRAM_HPP
#define FANTASYGAMEENGINE_SHADERPROGRAM_HPP

#include <GL/glew.h>
//#include "glad/glad.h"
#include <string>
#include <iostream>
#include <boost/log/trivial.hpp>
#include <filesystem>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram {
public:
    ShaderProgram(std::string vertexFile, std::string fragmentFile);

    void bindProgram();

    void unbindProgram();

    virtual ~ShaderProgram();

    virtual void getAllUniformLocations() = 0;

    int getProgramId() { return this->programId; }

protected:
    // With layout qualifier, you can forgo the use of glBindAttribLocation entirely
    // https://www.khronos.org/opengl/wiki/Layout_Qualifier_(GLSL)

    GLint getUniformLocation(std::string uniformName);

    void loadUniform(GLint location, glm::mat4 matrix);

private:
    int programId = -1;
    int vertexShaderId = -1;
    int fragmentShaderId = -1;


    GLuint createShaders(std::string filename, int shaderType);

    char *readFile(char *fn);

    void printShaderInfoLog(GLuint obj);

    void printProgramInfoLog(GLuint obj);

};


#endif //FANTASYGAMEENGINE_SHADERPROGRAM_HPP
