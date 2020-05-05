
#include "DisplayManager.hpp"
#include "Renderer.hpp"
#include <vector>
#include "StaticShader.hpp"
#include "texture/ModelTexture.hpp"
#include "models/TexturedModel.hpp"
#include "model/Model.hpp"
#include "Shader.hpp"

#define STB_IMAGE_IMPLEMENTATION

#include "Loader.hpp"


int main(int argc, char **argv) {

    DisplayManager dm;
    GLFWwindow *window = dm.createDisplay();
//    std::shared_ptr<StaticShader> shader = std::make_shared<StaticShader>();
//    shader->getAllUniformLocations();
//    Renderer renderer(shader);
    stbi_set_flip_vertically_on_load(true);
    Shader ourShader("resources/shaders/basic3.vs.glsl",
                     "resources/shaders/basic3.fs.glsl");
    // load models
    // -----------
    Model ourModel(std::filesystem::path("resources/models/backpack/backpack.obj"));

//    Loader loader;
//    RawModel model = loader.loadToVAO(vertices, textureCoords, indices);
//    ModelTexture texture(loader.loadTexture(tex));
//    TexturedModel texturedModel(model, texture);
//    Entity entity(texturedModel, std::move(glm::vec3(0.0, 0.0, -3)),
//                  0.0f, 0.0f, 0.0f, 1.0f);
// build and compile shaders
    // -------------------------

    // load models
    // -----------

    float deltaTime = 0.0f;    // time between current frame and last frame
    float lastFrame = 0.0f;
    float currentFrame = 0.0f;
    auto camera = dm.getCamera();
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window)) {

        // per-frame time logic
        // --------------------
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        dm.processInput(window, camera, deltaTime);

        /* Render here */
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // don't forget to enable shader before setting uniforms
        ourShader.use();

        glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom),
                (float) dm.WIDTH / (float) dm.HEIGHT, 0.1f,
                                                100.0f);
        ourShader.setMat4("projection", projection);
        // view/projection transformations
        glm::mat4 view = camera->GetViewMatrix();
        ourShader.setMat4("view", view);

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model,
                               glm::vec3(0.0f, 0.0f, -2.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));    // it's a bit too big for our scene, so scale it down
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);
//        entity.increaseRotation(0.3f, 1.0f, -1.0f);

//        shader->bindProgram();
//        // move camera
//        shader->loadViewMatrix(camera->GetViewMatrix());
//
//
//        renderer.render(entity, shader.get());
//        shader->unbindProgram();
        dm.updateDisplay();
    }
    return 0;
}
