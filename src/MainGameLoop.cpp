
#include "DisplayManager.hpp"
#include "Renderer.hpp"
#include <vector>
#include "StaticShader.hpp"
#include "texture/ModelTexture.hpp"
#include "models/TexturedModel.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "Loader.hpp"


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

    std::vector<float> textureCoords = {
            0.0, 0.0,
            0.0, 1.0,
            1.0, 1.0,
            1.0, 0.0,
    };
    Loader loader;
    RawModel model = loader.loadToVAO(vertices, textureCoords, indices);
//    std::string tex = "resources/texture/earth_256x256.png";
    std::string tex = "resources/texture/pointillist.bmp";
    ModelTexture texture(loader.loadTexture(tex));
    TexturedModel texturedModel(model, texture);
    Renderer renderer;
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        renderer.prepare();
        shader->start();
        renderer.render(texturedModel);
        shader->stop();
        dm.updateDisplay();
    }
    return 0;
}

