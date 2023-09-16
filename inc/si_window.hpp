//
// Created by etogood on 16.09.2023.
//

#ifndef SIENGINE_SI_WINDOW_HPP
#define SIENGINE_SI_WINDOW_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace si {
    class SiWindow {
    public:
        SiWindow(int w, int h, std::string name);
        ~SiWindow();

        SiWindow(const SiWindow &) = delete;
        SiWindow &operator=(const SiWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }
        VkExtent2D getExtent() { return {static_cast<uint32_t>(width),static_cast<uint32_t>(height)}; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        void initWindow();

        const int width;
        const int height;
        std::string windowName;
        GLFWwindow *window;
    };
}

#endif //SIENGINE_SI_WINDOW_HPP
