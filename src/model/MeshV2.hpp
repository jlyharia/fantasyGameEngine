//
// Created by Yihung Lee on 6/6/18.
//

#ifndef FANTASY_MESHV2_HPP
#define FANTASY_MESHV2_HPP

#include <vector>

class MeshV2 {
private:
    std::vector<unsigned int> indexList;
    std::vector<float> vertexList;
    std::vector<float> normalList;
public:
    const std::vector<unsigned int> &getIndexList() const { return this->indexList; }

    void setIndexList(const std::vector<unsigned int> &indexList) { this->indexList = indexList; }

    const std::vector<float> &getVertexList() const { return this->vertexList; }

    void setVertexList(const std::vector<float> &vertexList) { this->vertexList = vertexList; }

    const std::vector<float> &getNormalList() const { return this->normalList; }

    void setNormalList(const std::vector<float> &normalList) { this->normalList = normalList; }

};


#endif //FANTASY_MESHV2_HPP
