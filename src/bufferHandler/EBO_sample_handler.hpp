//
// Created by Yihung Lee on 5/17/18.
//

#ifndef FANTASY_EBO_SAMPLE_HPP
#define FANTASY_EBO_SAMPLE_HPP

#include "BufferHandler.hpp"

class EBO_sample_handler : public BufferHandler {
public:

    void prepare_buffer(GLRenderContext &glRenderContext) override;

    void draw(GLRenderContext &glRenderContext) override;
};


#endif //FANTASY_EBO_SAMPLE_HPP
