
#include "DisplayManager.hpp"
#include "Renderer.hpp"
#include "Loader.hpp"
#include <vector>

#include "shaderloader.hpp"

int main(int argc, char **argv) {
    DisplayManager dm;
    GLFWwindow *window = dm.createDisplay();


    std::vector<float> vertices = {
            -0.5f, 0.5f, 0.0f,//v0 top left
            -0.5f, -0.5f, 0.0f,//v1 bottom left
            0.5f, -0.5f, 0.0f,//v2 bottom right
            0.5f, 0.5f, 0.0f,//v3 top right
    };
//    std::vector<float> vertices = {
//            // Left bottom triangle
//            -0.5f, 0.5f, 0.0f,
//            -0.5f, -0.5f, 0.0f,
//            0.5f, -0.5f, 0.0f,
//            // Right top triangle
//            0.5f, -0.5f, 0.0f,
//            0.5f, 0.5f, 0.0f,
//            -0.5f, 0.5f, 0.0f
//    };
    std::vector<unsigned int> indices = {
            0, 1, 3,//top left triangle (v0, v1, v3)
            3, 1, 2//bottom right triangle (v3, v1, v2)
    };
    Loader loader;
    RawModel model = loader.loadToVAO(vertices, indices);
    Renderer renderer;
    GLuint shader_programme = createShaders("shaders/basic2");
    glUseProgram(shader_programme);
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        renderer.prepare();
        renderer.render(model);
        dm.updateDisplay();
    }
    return 0;
}

