//
// Created by Yihung Lee on 4/24/20.
//

#ifndef FANTASYGAMEENGINE_DEBUGHELPER_HPP
#define FANTASYGAMEENGINE_DEBUGHELPER_HPP

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

std::ostream &operator<<(std::ostream &out, const glm::vec3 &vec);
std::ostream &operator<<(std::ostream &out, const glm::vec4 &vec);
std::ostream &operator<<(std::ostream &out, const glm::mat3 &mat);
std::ostream &operator<<(std::ostream &out, const glm::mat4 &mat);


#endif //FANTASYGAMEENGINE_DEBUGHELPER_HPP
