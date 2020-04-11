//
// Created by Lee, Yihung on 4/23/18.
//

#ifndef FANTASY_VERTEXSHADERTYPE_HPP
#define FANTASY_VERTEXSHADERTYPE_HPP

#include "ShaderType.hpp"
#include <GL/glew.h>

class FragmentShaderType : ShaderType {
    virtual GLuint getShaderType() { return GL_FRAGMENT_SHADER; }

    virtual std::vector<std::string> getExtension() {
        return std::vector<std::string>{".fs.glsl", ".fs", "frag"};
    };

    static FragmentShaderType &getInstance() {
        static FragmentShaderType INSTANCE; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return INSTANCE;
    }

    FragmentShaderType(FragmentShaderType const &) = delete;

    void operator=(FragmentShaderType const &)  = delete;

private:

    FragmentShaderType() {}
};

#endif //FANTASY_VERTEXSHADERTYPE_HPP
