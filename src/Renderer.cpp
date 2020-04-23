//
// Created by Yihung Lee on 4/11/20.
//

#include "Renderer.hpp"


void Renderer::prepare() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glClearColor(0.5, 0.7, 0.8, 1);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

}

void Renderer::render(TexturedModel texturedModel) {
    RawModel model = texturedModel.getRawModel();
    glBindVertexArray(model.getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturedModel.getModelTexture().getTextureId());
    glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}