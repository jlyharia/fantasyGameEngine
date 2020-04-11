//
// Created by Yihung Lee on 4/21/18.
//

#ifndef FANTASY_GL_HANDLER_HPP
#define FANTASY_GL_HANDLER_HPP

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::mat3;

class gl_handler {
public:
    gl_handler() {}

    gl_handler(GLuint _loc_shader) : loc_shader(_loc_shader) {}

    ~gl_handler() {}

    int getUniformLocation(const char *uniformName);

    void sendUniform(const char *uniformName, float x, float y, float z);

    void sendUniform(const char *uniformName, const vec2 &v);

    void sendUniform(const char *uniformName, const vec3 &v);

    void sendUniform(const char *uniformName, const vec4 &v);

    void sendUniform(const char *uniformName, const mat4 &m);

    void sendUniform(const char *uniformName, const mat3 &m);

    void sendUniform(const char *uniformName, float val);

    void sendUniform(const char *uniformName, int val);

    void sendUniform(const char *uniformName, bool val);

    void setLocShader(GLuint);

private:
    GLuint loc_shader;
};


#endif //FANTASY_GL_HANDLER_HPP
