//
// Created by Yihung Lee on 6/6/18.
//
#define BOOST_LOG_DYN_LINK 1

#include "../shaderloader.hpp"
#include "CubeHandler.hpp"
#include "../modelLoader/AssimpModelLoader.hpp"

void CubeHandler::prepare_buffer(GLRenderContext &glRenderContext) {
    auto filePath = "../../geometric_data/cube.obj";
    auto mesh = AssimpModelLoader::createMesh(filePath);
    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh.getVertexList().size() * sizeof(float), &mesh.getVertexList()[0],
                 GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *) NULL);
    glEnableVertexAttribArray(0);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.getIndexList().size() * sizeof(unsigned int), &mesh.getIndexList()[0],
                 GL_DYNAMIC_DRAW);

    GLuint shader_programme = createShaders("shaders/basic2");
    glUseProgram(shader_programme);
    glRenderContext.setVao(vao);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void CubeHandler::draw(GLRenderContext &glRenderContext) {
    glBindVertexArray(glRenderContext.getVao());
    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // update other events like input handling
}