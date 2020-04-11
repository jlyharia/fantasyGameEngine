//
// Created by Lee, Yihung on 1/23/18.
//

#ifndef FANTASY_GFCONTEXT_HPP
#define FANTASY_GFCONTEXT_HPP

#include <OpenGL/OpenGL.h>

class GLRenderContext {

private:
    GLuint vao;

public:
    GLuint getVao() const {
        return vao;
    }

    void setVao(GLuint vao) {
        this->vao = vao;
    }
};

#endif //FANTASY_GFCONTEXT_HPP
