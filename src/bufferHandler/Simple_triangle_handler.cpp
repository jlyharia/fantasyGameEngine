//
// Created by Yihung Lee on 5/18/18.
//
#include "../shaderloader.hpp"
#include "Simple_triangle_handler.hpp"

void Simple_triangle_handler::prepare_buffer(GLRenderContext &glRenderContext) {
    float points[] = {
            0.0f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
    };
    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);


    GLuint vbo = 0;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *) NULL);
    glEnableVertexAttribArray(0);


    GLuint shader_programme = createShaders("resources/shaders/basic2");
    glUseProgram(shader_programme);
    glRenderContext.setVao(vao);
}

void Simple_triangle_handler::draw(GLRenderContext &glRenderContext) {
    glBindVertexArray(glRenderContext.getVao());
    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // update other events like input handling
}