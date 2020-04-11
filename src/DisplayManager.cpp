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
GLFWwindow* DisplayManager::createDisplay() {
    glfwSetErrorCallback(error_callback);
    // GLFW
    if (!glfwInit())
        exit(EXIT_FAILURE);


    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
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
    glewInit();

    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, key_callback);
    return window;
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    std::cout << "Destructor of DisplayManager invoked..." << '\n';
    glfwDestroyWindow(this->window);
    glfwTerminate();
    std::cout << "GLFW windows close" << '\n';
}