//
// Created by Lee, Yihung on 4/23/18.
//

#ifndef FANTASY_SHADER_LOADER_HPP
#define FANTASY_SHADER_LOADER_HPP

#include <GL/glew.h>
#include <string>
#include <vector>
#include "ShaderType.hpp"

class shader_loader {

public:

    GLuint createShaders(std::string vs_shader, std::string fs_shader);

private:
    char *textFileRead(char *);

    int textFileWrite(char *, char *);

    int printOglError(char *, int);

    void printShaderInfoLog(GLuint);

    void printProgramInfoLog(GLuint);

    std::string find_shader(std::string file_name, ShaderType shaderType);

/**
 * @return
 */
    GLuint createShaders(std::string filename);

    const std::vector<std::string> file_prefix = {"../src/resources/shaders/", "resources/shaders/"};


};


#endif //FANTASY_SHADER_LOADER_HPP
