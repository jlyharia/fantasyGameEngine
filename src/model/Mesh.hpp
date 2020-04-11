//
// Created by Yihung Lee on 5/22/18.
//

#ifndef FANTASY_MESH_HPP
#define FANTASY_MESH_HPP

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <vector>
#include "Vertex.hpp"


struct Texture {
    unsigned int id = 0;
    std::string type = "";
    std::string path = "";
};

class Mesh {
private:
    /*  Mesh Data  */
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    std::vector<float> vertexList;
    std::vector<float> normalList;
    std::vector<float> textureList;
public:
    const std::vector<float> &getVertexList() const;

    void setVertexList(const std::vector<float> &vertexList);

    const std::vector<float> &getNormalList() const;

    void setNormalList(const std::vector<float> &normalList);

    const std::vector<float> &getTextureList() const;

    void setTextureList(const std::vector<float> &textureList);

    Mesh();

    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);

    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices,
         const std::vector<Texture> &textures);

    const std::vector<Vertex> &getVertices() const;

    void setVertices(const std::vector<Vertex> &vertices);

    const std::vector<unsigned int> &getIndices() const;

    void setIndices(const std::vector<unsigned int> &indices);

    const std::vector<Texture> &getTextures() const;

    void setTextures(const std::vector<Texture> &textures);

};


#endif //FANTASY_MESH_HPP
