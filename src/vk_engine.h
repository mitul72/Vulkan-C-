﻿// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>

class VulkanEngine
{
public:
	// swapchain
	VkSwapchainKHR _swapchain; // from other articles

	// image format expected by the windowing system
	VkFormat _swapchainImageFormat;

	// array of images from the swapchain
	std::vector<VkImage> _swapchainImages;

	// array of image-views from the swapchain
	std::vector<VkImageView> _swapchainImageViews;

	VkInstance _instance;					   // Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger; // Vulkan debug output handle
	VkPhysicalDevice _chosenGPU;			   // GPU chosen as the default device
	VkDevice _device;						   // Vulkan device for commands
	VkSurfaceKHR _surface;					   // Vulkan window surface

	bool _isInitialized{false};
	int _frameNumber{0};

	VkExtent2D _windowExtent{850, 450};

	struct SDL_Window *_window{nullptr};

	// initializes everything in the engine
	void init();

	// shuts down the engine
	void cleanup();

	// draw loop
	void draw();

	// run main loop
	void run();

private:
	void init_vulkan();
	void init_swapchain();
};
