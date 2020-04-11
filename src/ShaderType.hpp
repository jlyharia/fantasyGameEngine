//
// Created by Lee, Yihung on 4/23/18.
//

#ifndef FANTASY_SHADERTYPE_HPP
#define FANTASY_SHADERTYPE_HPP

#include <GL/glew.h>
#include <string>
#include <vector>

class ShaderType {
public:
    virtual GLuint getShaderType()  = 0;

    virtual std::vector<std::string> getExtension() = 0;

};

#endif //FANTASY_SHADERTYPE_HPP
