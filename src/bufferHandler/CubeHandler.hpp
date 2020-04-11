//
// Created by Yihung Lee on 6/6/18.
//

#ifndef FANTASY_CUBEHANDLER_HPP
#define FANTASY_CUBEHANDLER_HPP

#include "BufferHandler.hpp"

class CubeHandler : public BufferHandler {
public:
    void prepare_buffer(GLRenderContext &glRenderContext) override;

    void draw(GLRenderContext &glRenderContext) override;
};


#endif //FANTASY_CUBEHANDLER_HPP
