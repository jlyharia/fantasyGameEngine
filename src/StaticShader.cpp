//
// Created by Yihung Lee on 4/12/20.
//

#include "StaticShader.hpp"


void StaticShader::getAllUniformLocations() {
    ShaderProgram::bindProgram();
    location_transformationMatrix = ShaderProgram::getUniformLocation("transformationMatrix");
    location_projectionMatrix = ShaderProgram::getUniformLocation("projectionMatrix");
    location_viewMatrix = ShaderProgram::getUniformLocation("viewMatrix");
}

void StaticShader::loadTransformationMatrix(glm::mat4 &matrix) {
    ShaderProgram::loadUniform(location_transformationMatrix, matrix);
}

void StaticShader::loadViewMatrix(glm::mat4 &&matrix) {
//    glm::mat4 viewMatrix = Maths::createViewMatrix(camera);
    ShaderProgram::loadUniform(location_viewMatrix, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 &projection) {
    ShaderProgram::loadUniform(location_projectionMatrix, projection);
}