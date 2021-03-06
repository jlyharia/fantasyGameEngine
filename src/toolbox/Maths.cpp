//
// Created by Yihung Lee on 4/23/20.
//

#include "Maths.hpp"


glm::mat4 Maths::createTransformationMatrix(const glm::vec3 translation,
                                            const float rx,
                                            const float ry,
                                            const float rz,
                                            const float scale) {
    // default is identity matrix
    glm::mat4 m(1);
    m = glm::translate(m, translation);
    m = glm::rotate(m, glm::radians(rx), glm::vec3(1, 0, 0));
    m = glm::rotate(m, glm::radians(ry), glm::vec3(0, 1, 0));
    m = glm::rotate(m, glm::radians(rz), glm::vec3(0, 0, 1));
    m = glm::scale(m, glm::vec3(scale));
    return m;
}


glm::mat4 Maths::createProjectionMatrix() {
    glm::mat4 projection = glm::perspective(
            glm::radians(45.0f),
            800.0f / 600.0f,
            0.1f,
            100.0f);
    return projection;
}