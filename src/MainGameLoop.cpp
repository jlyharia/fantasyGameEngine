
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
    Loader loader;
    GLFWwindow *window = dm.createDisplay();
    std::shared_ptr<StaticShader> shader = std::make_shared<StaticShader>();
    shader->getAllUniformLocations();
//    int pid = shader->getProgramId();
//    std::cout<<"program id = "<<pid<<std::endl;
//    glm::mat4 mat = Maths::createTransformationMatrix(
//            glm::vec3(-0.7, 0.0, 0.0),
//            0.0f,
//            0.0f,
//            0.0f,
//            1.0f);
//    glUseProgram(pid);
//    std::string matName ="transformationMatrix";
//    int loc =glGetUniformLocation(pid, matName.c_str());
//    std::cout<<"loc = "<<loc<<std::endl;
//    glUniformMatrix4fv(loc, 1, GL_FALSE, &mat[0][0]);


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
    RawModel model = loader.loadToVAO(vertices, textureCoords, indices);
    std::string tex = "resources/texture/pointillist.bmp";
    ModelTexture texture(loader.loadTexture(tex));
    TexturedModel texturedModel(model, texture);
    Entity entity(texturedModel, std::move(glm::vec3(-0.3, 0.3, -3)),
                  0.0f, 0.0f, 0.0f, 1.0f);

    Camera camera;
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        entity.increaseRotation(1.0f, 1.0f, 0.0f);
//        camera.move();

        renderer.prepare();
        shader->bindProgram();
        shader->loadViewMatrix(camera);


        renderer.render(entity, shader.get());
        shader->unbindProgram();
        dm.updateDisplay();
    }
    return 0;
}

