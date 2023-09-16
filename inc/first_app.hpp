//
// Created by etogood on 16.09.2023.
//

#ifndef SIENGINE_FIRST_APP_HPP
#define SIENGINE_FIRST_APP_HPP

#include "si_window.hpp"
#include "si_pipeline.hpp"
#include "si_swap_chain.hpp"

//std
#include <memory>

namespace si {
    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();

        ~FirstApp();

        FirstApp(const FirstApp &) = delete;

        FirstApp &operator=(const FirstApp &) = delete;

        void run();

    private:
        void createPipelineLayout();

        void createPipeline();

        void createCommandBuffers();

        void drawFrame();

        SiWindow siWindow{WIDTH, HEIGHT, "Hello, World!"};
        SiDevice siDevice{siWindow};
        SiSwapChain siSwapChain{siDevice, siWindow.getExtent()};
        std::unique_ptr<SiPipeline> siPipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
    };
}
#endif //SIENGINE_FIRST_APP_HPP
