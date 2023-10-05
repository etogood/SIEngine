//
// Created by etogood on 05.10.2023.
//

#pragma once

#include "si_device.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

namespace si {
    class SiModel {
    public:

        struct Vertex {
            glm::vec2 position;

            static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
        };

        SiModel(SiDevice &device, const std::vector<Vertex> &vertices);
        ~SiModel();
        SiModel(const SiModel &) = delete;
        SiModel &operator=(const SiModel &) = delete;

        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);

    private:
        void createVertexBuffers(const std::vector<Vertex> &vertices);

        SiDevice& siDevice;
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        uint32_t vertexCount;
    };
}