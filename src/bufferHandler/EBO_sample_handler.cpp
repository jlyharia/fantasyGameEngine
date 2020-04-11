//
// Created by Yihung Lee on 5/17/18.
//
#include "../shaderloader.hpp"
#include "EBO_sample_handler.hpp"


void EBO_sample_handler::prepare_buffer(GLRenderContext &glRenderContext) {
    float points[] = {
            0.0f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
    };
    unsigned int indices[]{
            0, 1, 2
    };
    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);


    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *) NULL);
    glEnableVertexAttribArray(0);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

    GLuint shader_programme = createShaders("resources/shaders/basic2");
    glUseProgram(shader_programme);
    glRenderContext.setVao(vao);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void EBO_sample_handler::draw(GLRenderContext &glRenderContext) {
    glBindVertexArray(glRenderContext.getVao());
    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // update other events like input handling
}