//
// Created by etogood on 16.09.2023.
//

#ifndef SIENGINE_SI_PIPELINE_HPP
#define SIENGINE_SI_PIPELINE_HPP

#include "si_device.hpp"

// std
#include <string>
#include <vector>

namespace si {
    struct PipelineConfigInfo {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    class SiPipeline {
    public:
        SiPipeline(
                SiDevice &device,
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);
        ~SiPipeline();
        SiPipeline(const SiPipeline&) = delete;
        void operator=(const SiPipeline&) = delete;

        void bind(VkCommandBuffer commandBuffer);
        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& filepath);
        void createGraphicsPipeline(
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        SiDevice& siDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}

#endif //SIENGINE_SI_PIPELINE_HPP
