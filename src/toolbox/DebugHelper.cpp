//
// Created by Yihung Lee on 4/24/20.
//

#include "DebugHelper.hpp"

std::ostream &operator<<(std::ostream &out, const glm::vec3 &vec) {
    out << glm::to_string(vec);
    return out;
}

std::ostream &operator<<(std::ostream &out, const glm::vec4 &vec) {
    out << glm::to_string(vec);
    return out;
}

std::ostream &operator<<(std::ostream &out, const glm::mat3 &mat) {
    out << glm::to_string(mat);
    return out;
}

std::ostream &operator<<(std::ostream &out, const glm::mat4 &mat) {
    out << glm::to_string(mat);
    return out;
}