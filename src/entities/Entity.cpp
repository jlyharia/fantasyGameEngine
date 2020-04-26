//
// Created by Yihung Lee on 4/24/20.
//

#include "Entity.hpp"

void Entity::increasePosition(float &dx, float &dy, float &dz) {
    this->position.x += dx;
    this->position.y += dy;
    this->position.z += dz;
}

void Entity::increaseRotation(float dx, float dy, float dz) {
    this->rotX += dx;
    this->rotY += dy;
    this->rotZ += dz;
}

const TexturedModel &Entity::getModel() const {
    return model;
}

void Entity::setModel(const TexturedModel &model) {
    Entity::model = model;
}

const glm::vec3 &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const glm::vec3 &position) {
    Entity::position = position;
}

float Entity::getRotX() const {
    return rotX;
}

void Entity::setRotX(float rotX) {
    Entity::rotX = rotX;
}

float Entity::getRotY() const {
    return rotY;
}

void Entity::setRotY(float rotY) {
    Entity::rotY = rotY;
}

float Entity::getRotZ() const {
    return rotZ;
}

void Entity::setRotZ(float rotZ) {
    Entity::rotZ = rotZ;
}

float Entity::getScale() const {
    return scale;
}

void Entity::setScale(float scale) {
    Entity::scale = scale;
}
