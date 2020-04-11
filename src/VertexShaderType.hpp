//
// Created by Lee, Yihung on 4/23/18.
//

#ifndef FANTASY_VERTEXSHADERTYPE_HPP
#define FANTASY_VERTEXSHADERTYPE_HPP

#include "ShaderType.hpp"
#include <GL/glew.h>

class VertexShaderType : ShaderType {
public:
    GLuint getShaderType() { return GL_VERTEX_SHADER; }

    std::vector<std::string> getExtension() {
        return std::vector<std::string>{".vs.glsl", ".vs", "vert"};
    };

    static VertexShaderType &getInstance() {
        static VertexShaderType INSTANCE; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return INSTANCE;
    }

    VertexShaderType(VertexShaderType const &) = delete;

    void operator=(VertexShaderType const &)  = delete;

private:

    VertexShaderType() {}

};

#endif //FANTASY_VERTEXSHADERTYPE_HPP
