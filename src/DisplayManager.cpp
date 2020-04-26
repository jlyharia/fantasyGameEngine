//
// Created by Yihung Lee on 4/10/20.
//

#include "DisplayManager.hpp"


void DisplayManager::error_callback(int error, const char *description) {
    fputs(description, stderr);
}

void DisplayManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

/**
 * Creates a display window on which we can render our game. The dimensions
 * of the window are determined by setting the display mode. By using
 * "glViewport" we tell OpenGL which part of the window we want to render
 * our game onto. We indicated that we want to use the entire window.
 */
GLFWwindow *DisplayManager::createDisplay() {
    glfwSetErrorCallback(error_callback);
    // GLFW
    if (!glfwInit())
        exit(EXIT_FAILURE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // init glfw windows
    this->window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    // Load the OpenGL functions.
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << '\n';
    std::cout << "GL_SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n';
    std::cout << "GL_VENDOR: " << glGetString(GL_VENDOR) << '\n';
    std::cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << '\n';
    std::cout << "GLFW Version: " << glfwGetVersionString() << '\n';

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    glewInit();


    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
//        std::cout << "Failed to initialize GLAD" << std::endl;
////        return -1;
//    }
    return window;
}

void DisplayManager::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
/**
 * This method is used to update the display at the end of every frame. When
 * we have set up a rendering process this method will display whatever
 * we've been rendering onto the screen. The "sync" method is used here to
 * cap the frame rate. Without this the computer would just try to run the
 * game as fast as it possibly can, doing more work than it needs to.
 */
// Sync fps
// http://forum.lwjgl.org/index.php?topic=5653.0
void DisplayManager::updateDisplay() {

    glfwPollEvents();

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
}

/**
 * This closes the window when the game is closed.
 */
DisplayManager::~DisplayManager() {
    std::cout << "Destructor of DisplayManager is invoked..." << '\n';
    glfwDestroyWindow(this->window);
    glfwTerminate();
    std::cout << "GLFW windows close" << '\n';
}