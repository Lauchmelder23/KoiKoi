#include "Window.hpp"

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

	glfwSetFramebufferSizeCallback(window, 
		[](GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
			UserData* data = (UserData*)glfwGetWindowUserPointer(window);
			data->camera->Update(0.0f, ((float)width / (float)height) * 1.0f, 0.0f, 1.0f, -100.0f, 100.0f);
		}
	);

	camera = lol::OrthogonalCamera(0.0f, ((float)width / (float)height) * 1.0f, 0.0f, 1.0f);
	data.camera = &camera;
	spdlog::debug("Created orthogonal camera");

	glfwSetWindowUserPointer(window, (void*)&data);
}

Window::~Window()
{
	if (valid)
	{
		glfwDestroyWindow(window);
		spdlog::debug("Destroyed GLFWwindow");
	}
}

void Window::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::Draw(lol::Layer& layer)
{
	layer.OnRender(camera);
}

void Window::Display()
{
	glfwSwapBuffers(window);
}
