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
        bool wasWindowResized() { return framebufferResized; }
        void resetWindowResizeFlag() { framebufferResized = false; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
        void initWindow();

        int width;
        int height;
        bool framebufferResized = false;

        std::string windowName;
        GLFWwindow *window;
    };
}

#endif //SIENGINE_SI_WINDOW_HPP
