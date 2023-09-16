//
// Created by etogood on 16.09.2023.
//

#include "si_window.hpp"

#include <stdexcept>

namespace si {

    SiWindow::SiWindow(int w, int h, std::string name) : width{w}, height(h), windowName{name} {
        initWindow();
    }

    SiWindow::~SiWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void SiWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    void SiWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface");
        }
    }
}

