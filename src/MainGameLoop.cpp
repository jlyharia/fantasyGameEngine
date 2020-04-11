
#include "DisplayManager.hpp"

int main(int argc, char **argv) {
    DisplayManager dm;
    GLFWwindow *window = dm.createDisplay();

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        dm.updateDisplay();
    }
    return 0;
}