//
// Created by Lee, Yihung on 6/1/18.
//

#include "Vertex.hpp"

const glm::vec3 &Vertex::getPosition() const {
    return position;
}

void Vertex::setPosition(const glm::vec3 &position) {
    Vertex::position = position;
}

const glm::vec3 &Vertex::getNormal() const {
    return normal;
}

void Vertex::setNormal(const glm::vec3 &normal) {
    Vertex::normal = normal;
}

const glm::vec2 &Vertex::getTexCoords() const {
    return texCoords;
}

void Vertex::setTexCoords(const glm::vec2 &texCoords) {
    Vertex::texCoords = texCoords;
}

const glm::vec3 &Vertex::getTangent() const {
    return tangent;
}

void Vertex::setTangent(const glm::vec3 &tangent) {
    Vertex::tangent = tangent;
}

const glm::vec3 &Vertex::getBitangent() const {
    return bitangent;
}

void Vertex::setBitangent(const glm::vec3 &bitangent) {
    Vertex::bitangent = bitangent;
}
