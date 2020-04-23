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

class DisplayManager {
public:
    GLFWwindow* createDisplay();

    void updateDisplay();

    GLFWwindow *getWindow() { return this->window; }

    ~DisplayManager();

private:
    static void error_callback(int error, const char *description);

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    const int WIDTH = 720;
    const int HEIGHT = 480;
    const char *TITLE = "Fantasy game engine";

    GLFWwindow *window;
};


#endif //FANTASY_DISPLAYMANAGER_HPP
