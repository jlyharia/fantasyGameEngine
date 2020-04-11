//
// Created by Lee, Yihung on 6/1/18.
//

#ifndef FANTASY_VERTEX_HPP
#define FANTASY_VERTEX_HPP


#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>
class Vertex {
private:
    // position
    glm::vec3 position = glm::vec3(0.0f);
    // normal
    glm::vec3 normal = glm::vec3(0.0f);
    // texCoords
    glm::vec2 texCoords = glm::vec2(0.0);
    // tangent
    glm::vec3 tangent = glm::vec3(0.0f);
    // bi-tangent
    glm::vec3 bitangent = glm::vec3(0.0f);

    // original element index
    std::vector<glm::vec3> verticeList;
    std::vector<glm::vec3> NormalList;
    std::vector<glm::vec3> TextureCoorList;

public:
    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &position);

    const glm::vec3 &getNormal() const;

    void setNormal(const glm::vec3 &normal);

    const glm::vec2 &getTexCoords() const;

    void setTexCoords(const glm::vec2 &texCoords);

    const glm::vec3 &getTangent() const;

    void setTangent(const glm::vec3 &tangent);

    const glm::vec3 &getBitangent() const;

    void setBitangent(const glm::vec3 &bitangent);

public:
};


#endif //FANTASY_VERTEX_HPP
