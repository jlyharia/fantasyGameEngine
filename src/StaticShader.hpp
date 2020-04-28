//
// Created by Yihung Lee on 4/12/20.
//

#ifndef FANTASYGAMEENGINE_STATICSHADER_HPP
#define FANTASYGAMEENGINE_STATICSHADER_HPP


#include "ShaderProgram.hpp"
#include <string>
#include <glm/glm.hpp>
#include "entities/Camera.hpp"
#include "toolbox/Maths.hpp"

class StaticShader : public ShaderProgram {
public:
    StaticShader() :
            ShaderProgram("shaders/basic3.vs.glsl", "shaders/basic3.fs.glsl") {};

    void loadTransformationMatrix(glm::mat4 &matrix);

    void loadViewMatrix(glm::mat4 &&matrix);

    void loadProjectionMatrix(glm::mat4 &projection);

    void getAllUniformLocations() override;

private:
    const static std::string VERTEX_FILE;
    const static std::string FRAGMENT_FILE;
    GLint location_transformationMatrix = -1;
    GLint location_projectionMatrix = -1;
    GLint location_viewMatrix = -1;
};


#endif //FANTASYGAMEENGINE_STATICSHADER_HPP
