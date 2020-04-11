//
// Created by Yihung Lee on 5/18/18.
//

#ifndef FANTASY_SIMPLE_TRIANGLE_HANDLER_HPP
#define FANTASY_SIMPLE_TRIANGLE_HANDLER_HPP


#include "BufferHandler.hpp"

class Simple_triangle_handler : public BufferHandler {
    void prepare_buffer(GLRenderContext &glRenderContext) override;

    void draw(GLRenderContext &glRenderContext) override;
};


#endif //FANTASY_SIMPLE_TRIANGLE_HANDLER_HPP
