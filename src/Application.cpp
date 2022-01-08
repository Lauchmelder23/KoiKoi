#include "Application.hpp"

#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include "Window.hpp"

void Application::Run()
{
	if (!valid)
	{
		spdlog::error("Application could not be launched");
		return;
	}

	spdlog::debug("Launched Application");
	while (!window->ShouldClose())
	{
		glfwPollEvents();
		window->Display();
	}
}

Application::Application() :
	valid(true), window(nullptr)
{
	int success = glfwInit();
	if (success != GLFW_TRUE)
	{
		const char* buffer;
		int result = glfwGetError(&buffer);
		spdlog::critical("Failed to initialize GLFW: ({}) {}", result, buffer);

		valid = false;
		return;
	}
	spdlog::debug("GLFW initialized");

	window = new Window(800, 800, "Koi Koi");
	valid = window->IsValid();
}

Application::~Application()
{
	delete window;

	glfwTerminate();
	spdlog::debug("GLFW terminated");
}
