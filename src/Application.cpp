#include "Application.hpp"

#include <chrono>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <stbi_image.h>

#include "Window.hpp"
#include "Card.hpp"

#include "resources.h"

void Application::Run()
{
	if (!valid)
	{
		spdlog::error("Application could not be launched");
		return;
	}

	spdlog::debug("Launched Application");

	int currentMonth = 0;
	int currentType = 0;
	std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
	while (!window->ShouldClose())
	{
		glfwPollEvents();

		if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - begin).count() > 250)
		{
			begin = std::chrono::system_clock::now();
			currentType++;
			if (currentType > 3)
			{
				currentMonth++;
				if (currentMonth > 11)
					currentMonth = 0;

				currentType = 0;
			}

			card->UpdateSuitAndType(static_cast<Month>(currentMonth), currentType);
		}

		window->Clear();
		window->Draw(*card);
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

	window = new Window(1280, 720, "Koi Koi");
	valid = window->IsValid();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		spdlog::critical("Failed to load GL loader");
		valid = false;
		return;
	}
	spdlog::debug("Loaded GL loader");

	spdlog::debug("Loading resources...");

	lol::Image image((unsigned char*)card_atlas_png, card_atlas_png_size);
	manager.Create<lol::Texture2D>(0, image, lol::TextureFormat::RGBA);
	manager.Create<lol::Shader>(1, std::string((char*)card_vs, card_vs_size), std::string((char*)card_fs, card_fs_size));
	spdlog::debug("Done!");

	card = new Card(manager, Month::August, 0);

	glViewport(0, 0, 1280, 720);
}

Application::~Application()
{
	delete card;
	delete window;

	glfwTerminate();
	spdlog::debug("GLFW terminated");
}
