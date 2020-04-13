//
// Created by Yihung Lee on 4/12/20.
//

#ifndef FANTASYGAMEENGINE_STATICSHADER_HPP
#define FANTASYGAMEENGINE_STATICSHADER_HPP


#include "ShaderProgram.hpp"
#include <string>

class StaticShader : public ShaderProgram {
public:
    StaticShader() :
    ShaderProgram("shaders/basic3.vs.glsl", "shaders/basic3.fs.glsl")
    {};

protected:
    void bindAttributes() override;

private:
    const static std::string VERTEX_FILE;
    const static std::string FRAGMENT_FILE;
};


#endif //FANTASYGAMEENGINE_STATICSHADER_HPP
