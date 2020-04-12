
#include "DisplayManager.hpp"
#include "Renderer.hpp"
#include "Loader.hpp"
#include <vector>

int main(int argc, char **argv) {
    DisplayManager dm;
    GLFWwindow *window = dm.createDisplay();


    std::vector<float> vertices = {
            // Left bottom triangle
            -0.5f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            // Right top triangle
            0.5f, -0.5f, 0.0f,
            0.5f, 0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
    };
    Loader loader;
    RawModel model = loader.loadToVAO(vertices);
    Renderer renderer;
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        renderer.prepare();
        renderer.render(model);
        dm.updateDisplay();
    }
    return 0;
}