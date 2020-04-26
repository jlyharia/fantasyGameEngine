//
// Created by Yihung Lee on 4/24/20.
//

#ifndef FANTASYGAMEENGINE_ENTITY_HPP
#define FANTASYGAMEENGINE_ENTITY_HPP

#include <glm/glm.hpp>
#include "../models/TexturedModel.hpp"

class Entity {
public:

    Entity(TexturedModel &model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale) :
            model(model), position(position), rotX(rotX), rotY(rotY), rotZ(rotZ), scale(scale) {};

    void increasePosition(float &dx, float &dy, float &dz);

    void increaseRotation(float dx, float dy, float dz);

    const TexturedModel &getModel() const;

    void setModel(const TexturedModel &model);

    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &position);

    float getRotX() const;

    void setRotX(float rotX);

    float getRotY() const;

    void setRotY(float rotY);

    float getRotZ() const;

    void setRotZ(float rotZ);

    float getScale() const;

    void setScale(float scale);

private:
    TexturedModel model;
    glm::vec3 position;
    float rotX;
    float rotY;
    float rotZ;
    float scale;

};


#endif //FANTASYGAMEENGINE_ENTITY_HPP
