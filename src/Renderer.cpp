//
// Created by Yihung Lee on 4/11/20.
//

#include "Renderer.hpp"


Renderer::Renderer(std::shared_ptr<StaticShader> shader) {
    this->projectionMatrix = Maths::createProjectionMatrix();
    shader->bindProgram();
    shader->loadProjectionMatrix(projectionMatrix);
    shader->unbindProgram();
}

void Renderer::prepare() {
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

}

void Renderer::render(Entity entity, StaticShader *shader) {
    TexturedModel texturedModel = entity.getModel();
    RawModel rawModel = texturedModel.getRawModel();
    glBindVertexArray(rawModel.getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glm::mat4 transformationMatrix = Maths::createTransformationMatrix(
            entity.getPosition(),
            entity.getRotX(),
            entity.getRotY(),
            entity.getRotZ(),
            entity.getScale());
    shader->loadTransformationMatrix(transformationMatrix);

    glActiveTexture(GL_TEXTURE0);


    glBindTexture(GL_TEXTURE_2D, texturedModel.getModelTexture().getTextureId());
    glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, 0);


    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}