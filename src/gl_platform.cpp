//
// Created by Lee, Yihung on 8/8/17.
//
#include <iostream>
#include <GL/glew.h>
#include "gl_platform.hpp"

using namespace std;

static void error_callback(int error, const char *description) { fputs(description, stderr); }

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void gl_platform::init_glfw() {
    glfwSetErrorCallback(error_callback);
    // GLFW
    if (!glfwInit())
        exit(EXIT_FAILURE);


    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // init glfw windows
    this->window = glfwCreateWindow(720, 480, "Fantasy Project",
            nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    // Load the OpenGL functions.
    cout << "OpenGL Version: " << glGetString(GL_VERSION) << '\n';
    cout << "GL_SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n';
    cout << "GL_VENDOR: " << glGetString(GL_VENDOR) << '\n';
    cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << '\n';
    cout << "GLFW Version: " << glfwGetVersionString() << '\n';
    glewInit();

    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, key_callback);
}

gl_platform::gl_platform(BufferHandler &&bufferHandler) {
    init_glfw();
    this->bufferHandler = &bufferHandler;
}

double clockToMilliseconds(clock_t ticks) {
    // units/(units/time) => time (seconds) * 1000 = milliseconds
    return (ticks / (double) CLOCKS_PER_SEC) * 1000.0;
}

void gl_platform::start() {
    this->bufferHandler->prepare_buffer(this->renderContext);
}

void gl_platform::render() {

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->bufferHandler->draw(this->renderContext);
        glfwPollEvents();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}


gl_platform::~gl_platform() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
    cout << "GLFW windows close" << '\n';
}

