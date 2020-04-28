
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
    std::shared_ptr<StaticShader> shader = std::make_shared<StaticShader>();
    shader->getAllUniformLocations();


    Renderer renderer(shader);
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
    std::string tex = "resources/texture/pointillist.bmp";
    ModelTexture texture(loader.loadTexture(tex));
    TexturedModel texturedModel(model, texture);
    Entity entity(texturedModel, std::move(glm::vec3(-0.3, 0.3, -3)),
                  0.0f, 0.0f, 0.0f, 1.0f);


    float deltaTime = 0.0f;    // time between current frame and last frame
    float lastFrame = 0.0f;
    float currentFrame = 0.0f;
    auto camera = dm.getCamera();
    while (!glfwWindowShouldClose(window)) {

        // per-frame time logic
        // --------------------
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        dm.processInput(window, camera, deltaTime);

        /* Render here */
        entity.increaseRotation(0.3f, 1.0f, -1.0f);


        shader->bindProgram();
        // move camera
        shader->loadViewMatrix(camera->GetViewMatrix());

        renderer.prepare();

        renderer.render(entity, shader.get());
        shader->unbindProgram();
        dm.updateDisplay();
    }
    return 0;
}
