//
// Created by Yihung Lee on 4/12/20.
//

#include "StaticShader.hpp"

void StaticShader::bindAttributes() {
    ShaderProgram::bindAttribute(0, "position");
}