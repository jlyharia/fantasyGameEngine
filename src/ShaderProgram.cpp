//
// Created by Yihung Lee on 4/12/20.
//

#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(std::string vertexFile, std::string fragmentFile) {
    vertexShaderId = createShaders(vertexFile, GL_VERTEX_SHADER);
    fragmentShaderId = createShaders(fragmentFile, GL_FRAGMENT_SHADER);
    programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId); //program step 2. attach shader - vertex shader
    glAttachShader(programId, fragmentShaderId);//program step 2. attach shader - fragment shader
    glValidateProgram(programId);

    glLinkProgram(programId);
    //---------Troubleshooting: The InfoLog - program------------
    printProgramInfoLog(programId);
}


GLint ShaderProgram::getUniformLocation(std::string uniformName) {
    GLint loc = glGetUniformLocation(this->programId, uniformName.c_str());
    if (loc < 0) {
        std::cout << "Uniform: " << uniformName << " not found\n";
    }
    return loc;
}

void ShaderProgram::loadUniform(GLint location, glm::mat4 matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}

void ShaderProgram::bindProgram() {
    glUseProgram(this->programId);
}

void ShaderProgram::unbindProgram() {
    glUseProgram(0);
}

ShaderProgram::~ShaderProgram() {
    std::cout << "Destructor of ShaderProgram is invoked...\n";
    unbindProgram();
    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    glDeleteProgram(programId);
}

GLuint ShaderProgram::createShaders(std::string file_name, int shaderType) {
    char *vs = NULL;
    GLuint v = glCreateShader(shaderType);  //shader step 1. create shader  - vertex shader

    vs = readFile((char *) file_name.c_str());
    const char *vv = vs;

    if (vs == NULL) {
        std::cout << "Create shader program is fail: shader file not found, file_name: "
                  << file_name << '\n';
        std::cout << "Current path is " << std::filesystem::current_path() << '\n';
        return -1;
    }
    glShaderSource(v, 1, &vv, NULL);//shader step 2. shader source - vertex shader

    free(vs);

    glCompileShader(v);//shader step 3. compile shader - vertex shader

    //---------Troubleshooting: The InfoLog - shader------------
    printShaderInfoLog(v);

    return v;
}


char *ShaderProgram::readFile(char *fn) {
    FILE *fp;
    char *content = NULL;
    int count = 0;
    if (fn != NULL) {
        fp = fopen(fn, "rt");
        if (fp != NULL) {
            fseek(fp, 0, SEEK_END);
            count = ftell(fp);
            rewind(fp);
            if (count > 0) {
                content = (char *) malloc(sizeof(char) * (count + 1));
                count = fread(content, sizeof(char), count, fp);
                content[count] = '\0';
            }
            fclose(fp);
        }
    }
    return content;
}

void ShaderProgram::printShaderInfoLog(GLuint obj) {
    int infologLength = 0;
    int charsWritten = 0;
    char *infoLog;
    //The status of the compile steps can be queried in OpenGL 2.0
    //with the following function:
    glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &infologLength);
    //glGetShaderiv  ßX Returns a parameter from a shader object
    if (infologLength > 0) {
        infoLog = (char *) malloc(infologLength);
        glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
        //glGetShaderInfoLog  ßX Returns the information log for a shader object
        printf("%s\n", infoLog);
        free(infoLog);
    }
}

void ShaderProgram::printProgramInfoLog(GLuint obj) {
    int infologLength = 0;
    int charsWritten = 0;
    char *infoLog;
    //The status of the link step can be queried in OpenGL 2.0
    //with the following function:
    glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength);
    //glGetProgramiv  ßX Returns a parameter from a program object
    if (infologLength > 0) {
        infoLog = (char *) malloc(infologLength);
        glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog);
        //glGetProgramInfoLog  X Returns the information log for a program object
        printf("%s\n", infoLog);
        free(infoLog);
    }
}