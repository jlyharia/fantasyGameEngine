//
// Created by Yihung Lee on 5/18/18.
//

#ifndef FANTASY_BUFFERHANDLER_HPP
#define FANTASY_BUFFERHANDLER_HPP

#include "../GLRenderContext.hpp"

class BufferHandler {
public:
    virtual void prepare_buffer(GLRenderContext &glRenderContext) = 0;

    virtual void draw(GLRenderContext &glRenderContext) = 0;
};

#endif //FANTASY_BUFFERHANDLER_HPP
