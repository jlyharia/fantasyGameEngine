//
// Created by Yihung Lee on 4/11/20.
//

#ifndef FANTASYGAMEENGINE_RAWMODEL_HPP
#define FANTASYGAMEENGINE_RAWMODEL_HPP

#include <OpenGL/OpenGL.h>

class RawModel {
public:
    RawModel(int vaoId, int vertexCount) : vaoId(vaoId), vertexCount(vertexCount) {}

    GLuint getVaoId();

    uint32_t getVertexCount();

private:
    GLuint vaoId;
    uint32_t vertexCount;
};


#endif //FANTASYGAMEENGINE_RAWMODEL_HPP
