//
// Created by Yihung Lee on 4/23/20.
//

#ifndef FANTASYGAMEENGINE_MATHS_HPP
#define FANTASYGAMEENGINE_MATHS_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../entities/Camera.hpp"
#include "DebugHelper.hpp"
class Maths {
public:

    static glm::mat4 createTransformationMatrix(const glm::vec3 translation,
                                                const float rx,
                                                const float ry,
                                                const float rz,
                                                const float scale);

    static glm::mat4 createViewMatrix(Camera &camera);

    static glm::mat4 createProjectionMatrix();
};


#endif //FANTASYGAMEENGINE_MATHS_HPP
