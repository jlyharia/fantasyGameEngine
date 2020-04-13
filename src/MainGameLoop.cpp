
#include "DisplayManager.hpp"
#include "Renderer.hpp"
#include "Loader.hpp"
#include <vector>

#include "shaderloader.hpp"
#include "StaticShader.hpp"
#include <memory>

int main(int argc, char **argv) {
    DisplayManager dm;
    GLFWwindow *window = dm.createDisplay();
    std::unique_ptr<ShaderProgram> shader = std::make_unique<StaticShader>();
    std::vector<float> vertices = {
            -0.5f, 0.5f, 0.0f,//v0 top left
            -0.5f, -0.5f, 0.0f,//v1 bottom left
            0.5f, -0.5f, 0.0f,//v2 bottom right
            0.5f, 0.5f, 0.0f,//v3 top right
    };

    std::vector<unsigned int> indices = {
            0, 1, 3,//top left triangle (v0, v1, v3)
            3, 1, 2//bottom right triangle (v3, v1, v2)
    };
    Loader loader;
    RawModel model = loader.loadToVAO(vertices, indices);
    Renderer renderer;
//    GLuint shader_programme = createShaders("shaders/basic2");
//    glUseProgram(shader_programme);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        renderer.prepare();
        shader->start();
        renderer.render(model);
        shader->stop();
        dm.updateDisplay();
    }
    return 0;
}

