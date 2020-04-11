//
// Created by Yihung Lee on 6/5/18.
//

#ifndef FANTASY_ASSIMPMODELLOADER_HPP
#define FANTASY_ASSIMPMODELLOADER_HPP

#include "../model/MeshV2.hpp"
#include <string>

class AssimpModelLoader {
public:
    static MeshV2 createMesh(std::string filePath);
};


#endif //FANTASY_ASSIMPMODELLOADER_HPP
