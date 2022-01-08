#include "Window.hpp"

#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

Window::Window(int width, int height, const std::string& title) :
	window(NULL), valid(true)
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (window == NULL)
	{
		const char* buffer;
		int result = glfwGetError(&buffer);
		spdlog::critical("Failed to create GLFWwindow: ({}) {}", result, buffer);

		valid = false;
		return;
	}

	spdlog::debug("Created GLFWwindow \n\tDimensions = ({}px, {}px), \n\tTitle = {}, \n\tFullscreen = {}", width, height, title, "NO");
	glfwMakeContextCurrent(window);
}

Window::~Window()
{
	if (valid)
	{
		glfwDestroyWindow(window);
		spdlog::debug("Destroyed GLFWwindow");
	}
}

void Window::Display()
{
	glfwSwapBuffers(window);
}
