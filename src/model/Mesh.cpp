//
// Created by Yihung Lee on 5/22/18.
//

#include "Mesh.hpp"

const std::vector<Vertex> &Mesh::getVertices() const {
    return vertices;
}

void Mesh::setVertices(const std::vector<Vertex> &vertices) {
    Mesh::vertices = vertices;
}

const std::vector<unsigned int> &Mesh::getIndices() const {
    return indices;
}

void Mesh::setIndices(const std::vector<unsigned int> &indices) {
    Mesh::indices = indices;
}

const std::vector<Texture> &Mesh::getTextures() const {
    return textures;
}

void Mesh::setTextures(const std::vector<Texture> &textures) {
    Mesh::textures = textures;
}

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices,
           const std::vector<Texture> &textures) : vertices(vertices), indices(indices), textures(textures) {}

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices) : vertices(vertices),
                                                                                            indices(indices) {}

const std::vector<float> &Mesh::getVertexList() const {
    return vertexList;
}

void Mesh::setVertexList(const std::vector<float> &vertexList) {
    Mesh::vertexList = vertexList;
}

const std::vector<float> &Mesh::getNormalList() const {
    return normalList;
}

void Mesh::setNormalList(const std::vector<float> &normalList) {
    Mesh::normalList = normalList;
}

const std::vector<float> &Mesh::getTextureList() const {
    return textureList;
}

void Mesh::setTextureList(const std::vector<float> &textureList) {
    Mesh::textureList = textureList;
}
