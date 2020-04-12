//
// Created by Yihung Lee on 4/11/20.
//

#include "Renderer.hpp"

void Renderer::prepare() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5, 0.7, 0.8, 1);
}

void Renderer::render(RawModel model) {
    glBindVertexArray(model.getVaoId());
    glEnableVertexAttribArray(0);
//    glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
    glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}