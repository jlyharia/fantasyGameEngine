//
// Created by Yihung Lee on 4/10/20.
//

#ifndef FANTASY_DISPLAYMANAGER_HPP
#define FANTASY_DISPLAYMANAGER_HPP

// glew should include before GLFW
#include <GL/glew.h>
//#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "entities/Camera.hpp"

class DisplayManager {
public:

    GLFWwindow *createDisplay();

    void updateDisplay();

    GLFWwindow *getWindow() { return this->window; }

    ~DisplayManager();

    void processInput(GLFWwindow *window, std::shared_ptr<Camera> &camera, float &deltaTime);

    void static mouse_callback(GLFWwindow *window, double xpos, double ypos);

    static const std::shared_ptr<Camera> &getCamera();

    const static int WIDTH = 720;
    const static int HEIGHT = 480;

private:
    static void error_callback(int error, const char *description);

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);


    const char *TITLE = "Fantasy game engine";
    GLFWwindow *window;
    static float lastX;
    static float lastY;
    static bool firstMouse;
    static std::shared_ptr<Camera> camera;
};


#endif //FANTASY_DISPLAYMANAGER_HPP
