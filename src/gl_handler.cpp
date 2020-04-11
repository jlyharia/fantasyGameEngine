//
// Created by Yihung Lee on 4/21/18.
//

#include "gl_handler.hpp"
#include <iostream>

void gl_handler::sendUniform(const char *uniformName, float val) {
    int loc = getUniformLocation(uniformName);
    if (loc >= 0) {
        glUniform1f(loc, val);
    } else {
        printf("Uniform: %s not found.\n", uniformName);
    }
}

//-----------------------------------------------------------------------------
void gl_handler::sendUniform(const char *uniformName, float x, float y, float z) {
    int loc = getUniformLocation(uniformName);
    if (loc >= 0) {
        glUniform3f(loc, x, y, z);
    } else {
        printf("Uniform: %s not found.\n", uniformName);
    }
}

//-----------------------------------------------------------------------------
void gl_handler::sendUniform(const char *uniformName, const vec3 &v) {
    this->sendUniform(uniformName, v.x, v.y, v.z);
}

//-----------------------------------------------------------------------------
void gl_handler::sendUniform(const char *uniformName, const vec4 &v) {
    int loc = getUniformLocation(uniformName);
    if (loc >= 0) {
        glUniform4f(loc, v.x, v.y, v.z, v.w);
    } else {
        printf("Uniform: %s not found.\n", uniformName);
    }
}

//-----------------------------------------------------------------------------
void gl_handler::sendUniform(const char *uniformName, const mat3 &m) {
    int loc = getUniformLocation(uniformName);
    if (loc >= 0) {
        glUniformMatrix3fv(loc, 1, GL_FALSE, &m[0][0]);
    } else {
        printf("Uniform: %s not found.\n", uniformName);
    }
}

//-----------------------------------------------------------------------------
void gl_handler::sendUniform(const char *uniformName, const mat4 &m) {
    int loc = getUniformLocation(uniformName);
    if (loc >= 0) {
        glUniformMatrix4fv(loc, 1, GL_FALSE, &m[0][0]);

    } else {
        printf("Uniform: %s not found.\n", uniformName);
    }
}

//-----------------------------------------------------------------------------
int gl_handler::getUniformLocation(const char *uniformName) {
    return glGetUniformLocation(this->loc_shader, uniformName);
}

//-----------------------------------------------------------------------------
void gl_handler::setLocShader(GLuint loc) { this->loc_shader = loc; }
