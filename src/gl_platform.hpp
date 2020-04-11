//
// Created by Lee, Yihung on 8/8/17.
//

#ifndef CLION_GL_PLATFORM_HPP
#define CLION_GL_PLATFORM_HPP


#include <GLFW/glfw3.h>
#include "GLRenderContext.hpp"
#include "bufferHandler/BufferHandler.hpp"

class gl_platform {
private:

    void init_glfw();

    GLFWwindow *window;

    GLRenderContext renderContext;

    BufferHandler* bufferHandler;

    void prepare_buffer_data();

public:

    gl_platform(BufferHandler &&bufferHandler);

    gl_platform();

    ~gl_platform();

    void render();

    void start();

    void pre_render_stage();

protected:

};


#endif //CLION_GL_PLATFORM_HPP
